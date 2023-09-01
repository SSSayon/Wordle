#include "input_window.h"
#include <QDebug>

InputWindow::InputWindow(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(300, 100, 600, 600);
    setStyleSheet("background-color: #ffffff");

    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            Cells[row][col] = new Cell(this);
            Cells[row][col]->setPos(65 + col * 95, 10 + row * 100);
        }
    }
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

void InputWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyText = event->text();

    if (keyText.length() == 1 && keyText.at(0).isLetter()) 
    {
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (Cells[row][col]->getLetter().isEmpty()) {
                    Cells[row][col]->setLetter(keyText.toUpper());
                    Cells[row][col]->color = Cell::Color::black;
                    Cells[row][col]->changeColor();
                    return;
                }
            }
        }
    } 
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) 
    {
        int nowRow = -1, nowCol = -1;
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (!Cells[row][col]->getLetter().isEmpty()) {
                    if (nowCol != -1)
                    {
                        Cells[nowRow][nowCol]->setLetter("A");
                        Cells[nowRow][nowCol]->color = Cell::Color::green;
                        Cells[nowRow][nowCol]->changeColor();
                    }
                    return;
                }
                nowRow = row;
                nowCol = col;
            }
        }
    } 
    else if (event->key() == Qt::Key_Backspace) 
    {
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (!Cells[row][col]->getLetter().isEmpty()) {
                    Cells[row][col]->setLetter("");
                    Cells[row][col]->color = Cell::Color::gray;
                    Cells[row][col]->changeColor();
                    return;
                }
            }
        }
    } 
    else 
    {
        return;
    }
    return;
}