#include "keyboard_window.h"
#include "input_window.h"
#include <QDebug>

KeyboardWindow::KeyboardWindow(QWidget *parent, Game *game, InputWindow *inputWindow)
    : QWidget(parent), game(game), inputWindow(inputWindow)
{
    gridLayout = new QGridLayout(this);

    for (int i = 0; i < 26; i++)
    {
        Cells[i] = new Cell(this);
        Cells[i]->setType(2);
        Cells[i]->setLetter(QString(keyMap[i]));
        connect(Cells[i], SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));

        int row, column;
        if (i < 10) { row = 0; column = i*2; } 
        else if (i < 19) { row = 1; column = (i-10)*2+1; } 
        else { row = 2; column = (i-19)*2+3; }
        gridLayout->addWidget(Cells[i], row, column, 1, 2);
    }
    
    enterCell = new Cell(this);
    enterCell->setType(3);
    enterCell->setLetter("ENTER");
    connect(enterCell, SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
    gridLayout->addWidget(enterCell, 2, 0, 1, 3);

    backspaceCell = new Cell(this);
    backspaceCell->setType(4);
    backspaceCell->setLetter("BACK\nSPACE");
    connect(backspaceCell, SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
    gridLayout->addWidget(backspaceCell, 2, 17, 1, 3);

    setLayout(gridLayout);
}

KeyboardWindow::~KeyboardWindow()
{
    for (int i = 0; i < 26; ++i)
    {
        delete Cells[i];
    }
    delete backspaceCell;
    delete enterCell;
}

void KeyboardWindow::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}

void KeyboardWindow::onCellClicked(Cell *cell)
{
    inputWindow->keyClickEvent(cell->getLetter());
}

void KeyboardWindow::flushKeyboard()
{
    for (int i = 0; i < 26; i++)
    {
        Cells[i]->color = game->gameStatus.letter_color[KeyMap2[i]];
        Cells[i]->changeColor();
    }
}

void KeyboardWindow::resetKeyboard()
{
    for (int i = 0; i < 26; i++)
    {
        Cells[i]->color = Cell::Color::gray;
        Cells[i]->changeColor();
    }
}
