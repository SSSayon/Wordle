#ifndef MESSAGE_WINDOW_H
#define MESSAGE_WINDOW_H

#include <QLabel>
#include <QString>
#include "../core/game.h"

class InputWindow;

class MessageWindow : public QLabel
{
public:
    MessageWindow(QWidget *parent = nullptr, Game *game = nullptr, InputWindow *inputWindow = nullptr);
    ~MessageWindow();

    void setInputWindow(InputWindow *inputWindow);
    void setMessage(const QString &message);
    
private:
    QString message;

    Game *game;
    InputWindow *inputWindow;
};

#endif // MESSAGE_WINDOW_H
