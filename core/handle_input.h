#ifndef HANDEL_INPUT_H
#define HANDEL_INPUT_H

#include <QString>
#include "../gui/cell.h"

class CellManager
{
public:
    void handleKeyPress(const QString &keyText, Cell *cell);
    void handleEnter(Cell *cell);
    void handleBackspace(Cell *cell);
};

#endif // HANDEL_INPUT_H
