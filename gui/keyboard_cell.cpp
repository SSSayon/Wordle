#include "keyboard_cell.h"

KeyboardCell::KeyboardCell(QWidget *parent) : Cell(parent), QPushButton(parent)
{
    Cell::style = {90, 90, "#ffffff", 0, "#c6c9cc"};
    Cell::setStyle(Cell::style);

    Cell::letterStyle = {32, 22, "#000000", 45};
    // Cell::letterLabel = new QLabel("", this);
    QFont font = Cell::letterLabel->font();
    font.setFamily("Monospace");
    font.setBold(true);
    Cell::letterLabel->setFont(font);
    Cell::setLetterStyle(Cell::letterStyle);
    Cell::letterLabel->show();
}


KeyboardCell::~KeyboardCell()
{
    delete Cell::letterLabel;
}