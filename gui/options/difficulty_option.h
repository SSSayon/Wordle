#ifndef DIFFICULTY_OPTION_H
#define DIFFICULTY_OPTION_H

#include <QLabel>
#include <QMouseEvent>
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>

class Game;
class MessageWindow;

class DiffOption : public QLabel
{
    Q_OBJECT

private:
    Game *game;
    MessageWindow *messageWindow;

    QSvgRenderer *renderer;
    QPixmap *pixmap;
    QPainter *painter;

public:
    DiffOption(QWidget *parent = nullptr, Game *game = nullptr, MessageWindow *messageWindow = nullptr);
    ~DiffOption();

    void setIcon();
    void setMessageWindow(MessageWindow *messageWindow);

protected:
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // DIFFICULTY_OPTION_H
