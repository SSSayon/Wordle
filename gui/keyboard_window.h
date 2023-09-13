#ifndef KEYBOARD_WINDOW_H
#define KEYBOARD_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "cell.h"
#include "../core/game.h"

class InputWindow;

class KeyboardWindow : public QWidget
{
    Q_OBJECT

public:
    KeyboardWindow(QWidget *parent = nullptr, Game *game = nullptr, InputWindow *inputWindow = nullptr);
    ~KeyboardWindow(); 

    void setInputWindow(InputWindow *inputWindow);
    void flushKeyboard();
    void resetKeyboard();

public slots:
    void onCellClicked(Cell *cell);

private:
    QGridLayout *gridLayout;
    int KeyMap2[26] = {16, 22, 4, 17, 19, 24, 20, 8, 14, 15,
                       0, 18, 3, 5, 6, 7, 9, 10, 11,
                       25, 23, 2, 21, 1, 13, 12};

    Cell *Cells[26];
    QChar keyMap[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                        'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
                        'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    Cell *backspaceCell;
    Cell *enterCell;
        
    Game *game;
    InputWindow *inputWindow;
};

#endif // KEYBOARD_WINDOW_H
