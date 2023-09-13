#ifndef RESTART_OPTION_H
#define RESTART_OPTION_H

#include <QLabel>
#include <QMouseEvent>

class Game;
class InputWindow;
class KeyboardWindow;
class MessageWindow;

class RestartOption : public QLabel
{
    Q_OBJECT

private:
    Game *game;
    InputWindow *inputWindow;
    KeyboardWindow *keyboardWindow;
    MessageWindow *messageWindow;
    
protected:
    void mousePressEvent(QMouseEvent *event) override;

public:
    RestartOption(QWidget *parent = nullptr, Game *game = nullptr, 
                  InputWindow *inputWindow = nullptr,
                  KeyboardWindow *keyboardWindow = nullptr,
                  MessageWindow *messageWindow = nullptr);
    ~RestartOption();

    void setInputWindow(InputWindow *inputWindow);
    void setKeyboardWindow(KeyboardWindow *keyboardWindow);
    void setMessageWindow(MessageWindow *messageWindow);

// signals:
//     void restartClicked();

};

#endif // RESTART_OPTION_H
