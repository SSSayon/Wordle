#include "save_option.h"
#include "../../core/game.h"
#include "../message_window.h"
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDateTime>
#include <QDebug>

SaveOption::SaveOption(QWidget *parent, Game *game, MessageWindow *messageWindow)
    : QLabel(parent), game(game), messageWindow(messageWindow)
{
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/download-solid.svg"));
    QPixmap *pixmap = new QPixmap(30, 30);
    pixmap->fill(Qt::transparent);
    QPainter *painter = new QPainter(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setToolTip("Save Game");
}

SaveOption::~SaveOption() {}

void SaveOption::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << "Save clicked";
        if (!game->gameStatus.is_game_over)
        {
            messageWindow->setMessage("Cannot save game before game finished!");
            return;
        }
        QJsonObject json;
        json["game_mode"] = game->gameStatus.game_mode;
        json["is_game_won"] = game->gameStatus.is_game_won;
        json["guessed_words"] = QJsonArray::fromStringList(game->gameStatus.guessed_words);
        json["answer"] = game->gameStatus.ans_word.toUpper();

        QJsonDocument doc(json);
        QString defaultDir = QDir::currentPath() + "/log";
        if (!QDir(defaultDir).exists()) { QDir().mkdir(defaultDir); }
        QString defaultPath = defaultDir + "/" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".json";
        QString savePath = QFileDialog::getSaveFileName(nullptr, "Save Game", defaultPath, "JSON (*.json)");
        
        if (savePath.isEmpty()) 
        {
            messageWindow->setMessage("Save cancelled!");
            return; 
        }
        QFile file(savePath);
        if (!file.open(QIODevice::WriteOnly)) 
        {
            messageWindow->setMessage("Cannot open file!");
            return;
        }
        file.write(doc.toJson());
        messageWindow->setMessage("Game saved to " + savePath);
        file.close();
    }
}

void SaveOption::setMessageWindow(MessageWindow *messageWindow)
{
    this->messageWindow = messageWindow;
}
