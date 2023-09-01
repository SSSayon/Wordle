#ifndef KEYBOARD_CELL_H
#define KEYBOARD_CELL_H

#include "cell.h"
#include <QPushButton>

class KeyboardCell : public Cell, public QPushButton
{
    Q_OBJECT

public:
    KeyboardCell(QWidget *parent = nullptr) : Cell(parent), QPushButton(parent) {}
    ~KeyboardCell() {}
};

#endif // KEYBOARD_CELL_H
