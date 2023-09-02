#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QGridLayout>
#include "cell.h"
#include "../core/game.h"

class KeyboardWindow;

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget *parent = nullptr, Game *game = nullptr, KeyboardWindow *keyboardWindow = nullptr);
    ~InputWindow(); 

    void setKeyboardWindow(KeyboardWindow *keyboardWindow);

    void keyPressEvent(QKeyEvent *event);
    void keyClickEvent(const QString & key);

private:
    void flushColor(int signal, int row, int col);

    QGridLayout *gridLayout;
    Cell *Cells[6][5];
    
    Game *game;
    KeyboardWindow *keyboardWindow;
};

#endif // INPUT_WINDOW_H
