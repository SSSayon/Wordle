#include "input_window.h"
#include "keyboard_window.h"
#include "message_window.h"
#include <QDebug>

InputWindow::InputWindow(QWidget *parent, Game *game, KeyboardWindow *keyboardWindow, MessageWindow *messageWindow)
    : QWidget(parent), game(game), keyboardWindow(keyboardWindow), messageWindow(messageWindow)
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
void InputWindow::setMessageWindow(MessageWindow *messageWindow)
{
    this->messageWindow = messageWindow;
}

void InputWindow::_flushColor(int signal, int row, int col) // signal: 0: flush current row, 1: flush previous row
{
    if (signal == 0)
        Cells[row][col]->color = game->gameStatus.cur_word_color[col];
    else if (signal == 1)
        Cells[row][col]->color = game->gameStatus.prev_word_color[col];
    Cells[row][col]->changeColor();
    return;
}

void InputWindow::_handleKeyInput(int _signal, const QString & key)
{
    if (_signal == 1) // key input
    {
        int signal = game->handleKeyPress(key.toLower());
        if (signal == 1)
        {
            Cells[game->gameStatus.cur_row][game->gameStatus.cur_col - 1]->setLetter(key.toUpper());
            _flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col - 1);
        }
    }
    else if (_signal == 2) // backspace
    {
        int signal = game->handleBackspace();
        if (signal == 1)
            {
                Cells[game->gameStatus.cur_row][game->gameStatus.cur_col]->setLetter("");
                _flushColor(0, game->gameStatus.cur_row, game->gameStatus.cur_col);
            }
    }
    else // enter
    {
        if (game->gameStatus.wordDataSet.error_code == 1) return;
        int signal = game->handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid but hint unused, 3: word valid then enter
        if (game->gameStatus.game_mode == 0)
        {
            if ((signal == 2) || (signal == 3))
            {
                for (int i = 0; i < 5; i++)
                    _flushColor(1, game->gameStatus.cur_row - 1, i);
                keyboardWindow->flushKeyboard();
                messageWindow->setMessage("");
            }
            else
            {
                messageWindow->setMessage("Word not valid!");
            }
        }
        else
        {
            if (signal == 3)
            {
                for (int i = 0; i < 5; i++)
                    _flushColor(1, game->gameStatus.cur_row - 1, i);
                keyboardWindow->flushKeyboard();
                messageWindow->setMessage("");
            }
            else
            {
                if (signal == 1)
                    messageWindow->setMessage("Word not valid!");
                else if (signal == 2)
                    messageWindow->setMessage("Previous hint(s) unused!");
            }
        }

        if (game->gameStatus.is_game_over)
        {
            if (game->gameStatus.is_game_won)
                messageWindow->setMessage("You win!");
            else
                messageWindow->setMessage("You lose! The correct word is: " + game->gameStatus.ans_word.toUpper());
        }
        // if (signal != 0)
        //     qDebug() << game->getValidWords();
    }
    return;
}

void InputWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyText = event->text();
    if (keyText.length() == 1 && keyText.at(0).isLetter()) 
    {
        _handleKeyInput(1, keyText);
    }
    else if (event->key() == Qt::Key_Backspace) 
    {
        _handleKeyInput(2, "");
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) 
    {
        _handleKeyInput(3, "");
    }
    return;
}

void InputWindow::keyClickEvent(const QString & key)
{
    if (key == "BACK\nSPACE") 
    {
        _handleKeyInput(2, "");
    }
    else if (key == "ENTER") 
    {
        _handleKeyInput(3, "");
    }
    else 
    {
        _handleKeyInput(1, key);
    }
    return;
}

void InputWindow::resetInputWindow()
{
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            Cells[row][col]->setLetter("");
            Cells[row][col]->color = Cell::Color::gray;
            Cells[row][col]->changeColor();
        }
    }
    return;
}
