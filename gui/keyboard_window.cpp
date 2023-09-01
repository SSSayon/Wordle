#include "keyboard_window.h"
#include <QDebug>

KeyboardWindow::KeyboardWindow(QWidget *parent)
    : QWidget(parent)
{
    // setFocusPolicy(Qt::StrongFocus);
    setGeometry(262, 715, 676, 280);
    initKeyboard();
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

void KeyboardWindow::onCellClicked(Cell *cell)
{
    qDebug() << cell->getLetter() << " clicked";
}

void KeyboardWindow::initKeyboard()
{
    gridLayout = new QGridLayout(this);

    for (int i = 0; i < 26; i++)
    {
        Cells[i] = new Cell(this);
        Cells[i]->type = 2;
        Cells[i]->setStyle(64, 85, 8);
        Cells[i]->setLetterStyle(23, 22, 30, 45, 30);
        Cells[i]->setLetter(QString(keyMap[i]));
        connect(Cells[i], SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));

        int row, column;
        if (i < 10) { row = 0; column = i*2; } 
        else if (i < 19) { row = 1; column = (i-10)*2+1; } 
        else { row = 2; column = (i-19)*2+3; }
        gridLayout->addWidget(Cells[i], row, column, 1, 2);
    }
    enterCell = new Cell(this);
    enterCell->type = 2;
    enterCell->setStyle(98, 85, 8);
    enterCell->setLetterStyle(19, 22, 60, 45, 20);
    enterCell->setLetter("ENTER");
    connect(enterCell, SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
    gridLayout->addWidget(enterCell, 2, 0, 1, 3);
    backspaceCell = new Cell(this);
    backspaceCell->type = 2;
    backspaceCell->setStyle(98, 85, 8);
    backspaceCell->setLetterStyle(21, 23, 60, 45, 20);
    backspaceCell->setLetter("BACK\nSPACE");
    connect(backspaceCell, SIGNAL(cellClicked(Cell*)), this, SLOT(onCellClicked(Cell*)));
    gridLayout->addWidget(backspaceCell, 2, 17, 1, 3);

    setLayout(gridLayout);
}