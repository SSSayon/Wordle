#ifndef SAVE_OPTION_H
#define SAVE_OPTION_H

#include <QLabel>
#include <QMouseEvent>

class Game;
class MessageWindow;

class SaveOption : public QLabel
{
    Q_OBJECT

private:
    Game *game;
    MessageWindow *messageWindow;

public:
    SaveOption(QWidget *parent = nullptr, Game *game = nullptr, MessageWindow *messageWindow = nullptr);
    ~SaveOption();

    void setMessageWindow(MessageWindow *messageWindow);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SAVE_OPTION_H
