#include "restart_option.h"
#include "../../core/game.h"
#include "../input_window.h"
#include "../keyboard_window.h"
#include "../message_window.h"
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

RestartOption::RestartOption(QWidget *parent, Game *game, 
                             InputWindow *inputWindow,
                             KeyboardWindow *keyboardWindow,
                             MessageWindow *messageWindow)
    : QLabel(parent), game(game), 
      inputWindow(inputWindow),
      keyboardWindow(keyboardWindow),
      messageWindow(messageWindow)
{
    QSvgRenderer *renderer = new QSvgRenderer(QString(":/icons/arrow-rotate-right-solid.svg"));
    QPixmap *pixmap = new QPixmap(30, 30);
    pixmap->fill(Qt::transparent);
    QPainter *painter = new QPainter(pixmap);
    renderer->render(painter);
    painter->end();
    setPixmap(*pixmap);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setToolTip("Restart");
}

RestartOption::~RestartOption() {}

void RestartOption::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << "Restart clicked";
        // emit restartClicked();
        game->resetGame();
        inputWindow->resetInputWindow();
        keyboardWindow->resetKeyboard();
        messageWindow->resetMessage();
    }
}

void RestartOption::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}
void RestartOption::setKeyboardWindow(KeyboardWindow *keyboardWindow)
{
    this->keyboardWindow = keyboardWindow;
}
void RestartOption::setMessageWindow(MessageWindow *messageWindow)
{
    this->messageWindow = messageWindow;
}
