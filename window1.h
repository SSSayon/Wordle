#ifndef WINDOW1_H
#define WINDOW1_H

#include <QWidget>
#include <QPushButton>

class Window1 : public QWidget
{
public:
    Window1(QWidget *parent = nullptr);
    ~Window1();

    QPushButton *button1, *button2;

private:
    void createButton();
};

#endif // WINDOW1_H
