#ifndef MESSAGE_WINDOW_H
#define MESSAGE_WINDOW_H

#include <QLabel>
#include <QString>
#include "../core/game.h"

class InputWindow;

class MessageWindow : public QLabel
{
public:
    MessageWindow(QWidget *parent = nullptr, Game *game = nullptr);
    ~MessageWindow();

    void setMessage(const QString &message);
    void resetMessage();
    
private:
    QString message;
    Game *game;
};

#endif // MESSAGE_WINDOW_H
