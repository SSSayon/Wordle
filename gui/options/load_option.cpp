#include "load_option.h"
#include "../../core/game.h"
#include "../input_window.h"
#include "../message_window.h"
#include "difficulty_option.h"
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>
#include <QDir>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

LoadOption::LoadOption(QWidget *parent, Game *game, 
                       InputWindow *inputWindow, MessageWindow *messageWindow,
                       DiffOption *diffOption)
    : QLabel(parent), game(game), 
      inputWindow(inputWindow), messageWindow(messageWindow),
      diffOption(diffOption)
{
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/upload-solid.svg"));
    QPixmap *pixmap = new QPixmap(30, 30);
    pixmap->fill(Qt::transparent);
    QPainter *painter = new QPainter(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setToolTip("Load Game");
}

LoadOption::~LoadOption() {}

void LoadOption::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << "Load clicked";
        if (game->gameStatus.has_game_started)
        {
            messageWindow->setMessage("Cannot load game after game started!");
            return;
        }
        QString defaultDir = QDir::currentPath() + "/log";
        QString loadPath = QFileDialog::getOpenFileName(this, "Load Game", defaultDir, "JSON (*.json)");
        if (loadPath.isEmpty()) 
        {
            messageWindow->setMessage("Load cancelled!");
            return; 
        }
        QFile file(loadPath);
        if (!file.open(QIODevice::ReadOnly)) 
        {
            messageWindow->setMessage("Failed to open file from " + loadPath + "!");
            return;
        }
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isNull() || !doc.isObject()) 
        {
            messageWindow->setMessage("Failed to parse JSON from " + loadPath + "!");
            return;
        }
        QJsonObject json = doc.object();
        if (!json.contains("game_mode") || !json["game_mode"].isDouble() ||
            !json.contains("is_game_won") || !json["is_game_won"].isBool() ||
            !json.contains("guessed_words") || !json["guessed_words"].isArray() ||
            !json.contains("answer") || !json["answer"].isString()) 
        {
            messageWindow->setMessage("Invalid JSON from " + loadPath + "!");
            return;
        }
        QJsonArray guessed_words_array = json["guessed_words"].toArray();
        QStringList guessed_words;
        for (int i = 0; i < guessed_words_array.size(); i++)
        {
            guessed_words.append(guessed_words_array[i].toString());
            if (guessed_words[i].length() != 5)
            {
                messageWindow->setMessage("Invalid JSON from " + loadPath + "!");
                return;
            }
            for (int j = 0; j < 5; j++)
            {
                if (guessed_words[i][j] < 'A' || guessed_words[i][j] > 'Z')
                {
                    messageWindow->setMessage("Invalid JSON from " + loadPath + "!");
                    return;
                }
            }
        }
        // qDebug() << guessed_words;
        game->resetGame();
        game->gameStatus.game_mode = json["game_mode"].toInt();
        game->gameStatus.ans_word = json["answer"].toString().toLower();
        diffOption->setIcon();
        inputWindow->resetInputWindow();
        for (int i = 0; i < guessed_words.size(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                inputWindow->keyClickEvent(QString(guessed_words[i][j]));
            }
            inputWindow->keyClickEvent("ENTER");
        }
        
        messageWindow->setMessage("Game loaded from " + loadPath + "!");
    }
}

void LoadOption::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}
void LoadOption::setMessageWindow(MessageWindow *messageWindow)
{
    this->messageWindow = messageWindow;
}
void LoadOption::setDiffOption(DiffOption *diffOption)
{
    this->diffOption = diffOption;
}
