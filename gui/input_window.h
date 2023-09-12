#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QGridLayout>
#include "cell.h"
#include "../core/game.h"

class KeyboardWindow;
class MessageWindow;

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget *parent = nullptr, Game *game = nullptr, KeyboardWindow *keyboardWindow = nullptr, MessageWindow *messageWindow = nullptr);
    ~InputWindow(); 

    void setKeyboardWindow(KeyboardWindow *keyboardWindow);
    void setMessageWindow(MessageWindow *messageWindow);

    void keyPressEvent(QKeyEvent *event);
    void keyClickEvent(const QString & key);

private:
    void _handleKeyInput(int _signal, const QString & key);
    void _flushColor(int signal, int row, int col);

    QGridLayout *gridLayout;
    Cell *Cells[6][5];
    
    Game *game;
    KeyboardWindow *keyboardWindow;
    MessageWindow *messageWindow;
};

#endif // INPUT_WINDOW_H
