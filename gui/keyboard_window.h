#ifndef KEYBOARD_WINDOW_H
#define KEYBOARD_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "cell.h"

class KeyboardWindow : public QWidget
{
    Q_OBJECT

public:
    KeyboardWindow(QWidget *parent = nullptr);
    ~KeyboardWindow(); 

private:
    QGridLayout *gridLayout;
    void initKeyboard();
    Cell *Cells[26];
    QChar keyMap[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                     'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                     'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    Cell *backspaceCell;
    Cell *enterCell;

public slots:
    void onCellClicked(Cell *cell);
};

#endif // KEYBOARD_WINDOW_H
