#include "difficulty_option.h"
#include "../../core/game.h"
#include "../message_window.h"
#include <QDebug>

DiffOption::DiffOption(QWidget *parent, Game *game, MessageWindow *messageWindow)
    : QLabel(parent), game(game), messageWindow(messageWindow)
{
    renderer = new QSvgRenderer(QString(":/icons/face-smile-regular.svg"));
    pixmap = new QPixmap(30, 30);
    pixmap->fill(Qt::transparent);
    painter = new QPainter(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setToolTip("Difficulty: Normal");
}

DiffOption::~DiffOption() 
{
    delete renderer;
    delete pixmap;
    delete painter;
}

void DiffOption::setIcon()
{
    QString newIconPath;
    QString newToolTip;
    QString newMessage;
    if (game->gameStatus.game_mode == 0)
    {
        newIconPath = ":/icons/face-smile-regular.svg";
        newToolTip = "Difficulty: Normal";
        newMessage = "Difficulty changed to Normal!";
    }
    else
    {
        newIconPath = ":/icons/skull-solid.svg";
        newToolTip = "Difficulty: Hard";
        newMessage = "Difficulty changed to Hard!";
    }

    renderer->load(newIconPath);
    pixmap->fill(Qt::transparent);
    painter->begin(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);

    setToolTip(newToolTip);
    messageWindow->setMessage(newMessage);
}

void DiffOption::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << "Difficulty clicked";

        if (game->gameStatus.has_game_started)
        {
            messageWindow->setMessage("Cannot change difficulty after game started!");
            return;
        }

        game->gameStatus.game_mode = 1 - game->gameStatus.game_mode;
        
        setIcon();
    }
}

void DiffOption::setMessageWindow(MessageWindow *messageWindow)
{
    this->messageWindow = messageWindow;
}
