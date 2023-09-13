#ifndef LOAD_OPTION_H
#define LOAD_OPTION_H

#include <QLabel>
#include <QMouseEvent>

class Game;
class InputWindow;
class MessageWindow;
class DiffOption;

class LoadOption : public QLabel
{
    Q_OBJECT

private:
    Game *game;
    InputWindow *inputWindow;
    MessageWindow *messageWindow;
    DiffOption *diffOption;

public:
    LoadOption(QWidget *parent = nullptr, Game *game = nullptr, 
               InputWindow *inputWindow = nullptr, MessageWindow *messageWindow = nullptr,
               DiffOption *diffOption = nullptr);
    ~LoadOption();

    void setInputWindow(InputWindow *inputWindow);
    void setMessageWindow(MessageWindow *messageWindow);
    void setDiffOption(DiffOption *diffOption);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // LOAD_OPTION_H
