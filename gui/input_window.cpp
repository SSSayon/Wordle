#include "input_window.h"
#include "keyboard_window.h"
#include <QDebug>

InputWindow::InputWindow(QWidget *parent, Game *game, KeyboardWindow *keyboardWindow)
    : QWidget(parent), game(game), keyboardWindow(keyboardWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    // setGeometry(350, 100, 500, 600);
    setStyleSheet("background-color: #ffffff");

    gridLayout = new QGridLayout(this);
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            Cells[row][col] = new Cell(this);
            // Cells[row][col]->setStyle(90, 90, 0);
            // Cells[row][col]->setLetterStyle(32, 22, 30, 45, 45);
            gridLayout->addWidget(Cells[row][col], row, col);
        }
    }
    setLayout(gridLayout);
}

InputWindow::~InputWindow()
{
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            delete Cells[row][col];
        }
    }
}

void InputWindow::setKeyboardWindow(KeyboardWindow *keyboardWindow)
{
    this->keyboardWindow = keyboardWindow;
}

void InputWindow::flushColor(int signal, int row, int col) // signal: 0: flush current row, 1: flush previous row
{
    if (signal == 0)
        Cells[row][col]->color = game->gameStatus.cur_word_color[col];
    else if (signal == 1)
        Cells[row][col]->color = game->gameStatus.prev_word_color[col];
    Cells[row][col]->changeColor();
    return;
}

void InputWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyText = event->text();
    if (keyText.length() == 1 && keyText.at(0).isLetter()) 
    {
        int signal = game->handleKeyPress(keyText.toLower());
        if (signal == 1)
        {
            Cells[game->gameStatus.cur_row][game->gameStatus.cur_col - 1]->setLetter(keyText.toUpper());
            flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col - 1);
        }
    }
    else if (event->key() == Qt::Key_Backspace) 
    {
        int signal = game->handleBackspace();
        if (signal == 1)
            {
                Cells[game->gameStatus.cur_row][game->gameStatus.cur_col]->setLetter("");
                flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col);
            }
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) 
    {
        int signal = game->handleEnter();
        if (signal == 2)
        {
            for (int i = 0; i < 5; i++)
                flushColor(1, game->gameStatus.cur_row - 1, i);
            keyboardWindow->flushKeyboard();
        }
    }
    return;
}

void InputWindow::keyClickEvent(const QString & key)
{
    if (key == "BACK\nSPACE") 
    {
        int signal = game->handleBackspace();
        if (signal == 1)
            {
                Cells[game->gameStatus.cur_row][game->gameStatus.cur_col]->setLetter("");
                flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col);
            }
    }
    else if (key == "ENTER") 
    {
        int signal = game->handleEnter();
        if (signal == 2)
        {
            for (int i = 0; i < 5; i++)
                flushColor(1, game->gameStatus.cur_row - 1, i);
            keyboardWindow->flushKeyboard();
        }
    }
    else 
    {
        int signal = game->handleKeyPress(key.toLower());
        if (signal == 1)
        {
            Cells[game->gameStatus.cur_row][game->gameStatus.cur_col - 1]->setLetter(key);
            flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col - 1);
        }
    }
    return;
}
