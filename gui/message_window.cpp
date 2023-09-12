#include "message_window.h"
#include "input_window.h"

MessageWindow::MessageWindow(QWidget *parent, Game *game, InputWindow *inputWindow)
    : QLabel(parent), game(game), inputWindow(inputWindow)
{
    if (game->gameStatus.wordDataSet.error_code == 0)
        message = "Welcome to Wordle!";
    else
        message = "Dataset loading failed!";
    setText(message);
    QFont font2 = font();
    font2.setFamily("Consolas");
    font2.setPointSize(14);
    setFont(font2);
}

MessageWindow::~MessageWindow() {}

void MessageWindow::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}

void MessageWindow::setMessage(const QString &message)
{
    this->message = message;
    setText(message);
}