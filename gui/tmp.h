#ifndef WINDOW1_H
#define WINDOW1_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QTimer>

class Button;

class Window1 : public QWidget
{
    Q_OBJECT
public:
    Window1(QWidget *parent = nullptr);
    ~Window1(); 

private:
    Button *button1, *button2;
    void createButton();
    QTimer *timer1, *timer2;
    void createTimer();
};

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button();
    Button(QString label, QWidget *parent = nullptr);
    void setGeometry(int x, int y, int width, int height);
    ~Button();

private:
    int init_x, init_y;
    
// public slots:
//     void hide();
//     void show();
    // void show(QString label); // with changed label
};

#endif // WINDOW1_H
