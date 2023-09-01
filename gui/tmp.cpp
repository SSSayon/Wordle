#include "tmp.h"

Window1::Window1(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(300, 100, 600, 600);
    createButton();
    // createTimer();
}

Window1::~Window1()
{
    delete button1;
    delete button2;
    // delete timer1;
    // delete timer2;
}

void Window1::createButton()
{
    button1 = new Button("Button1", this);
    button1->setGeometry(10, 10, 80, 30);
    connect(button1, &QPushButton::clicked, 
            button1, &Button::hide);

    button2 = new Button();
    button2->setText("Button2");
    button2->setParent(this);
    button2->setGeometry(10, 40, 80, 30);
    connect(button2, &QPushButton::clicked,
            button1, &Button::show);
    // connect(button2, &QPushButton::clicked,
    //         [=]()->void{button1->show();});
    // void (Button::*showWithChangedLabel)(QString) = &Button::show;
    // connect(button2, &QPushButton::clicked, button1, 
    //         [=]()->void{(button1->*showWithChangedLabel)(button2->text());});
}

void Window1::createTimer()
{
    timer1 = new QTimer(this);
    timer1->setInterval(2000);
    timer1->setTimerType(Qt::PreciseTimer);
    connect(timer1, &QTimer::timeout, 
            button1, &Button::hide);
    connect(timer1, &QTimer::timeout, 
            [&]()->void{timer2->start();timer1->stop();});

    timer2 = new QTimer(this);
    timer2->setInterval(2000);
    timer2->setTimerType(Qt::PreciseTimer);
    connect(timer2, &QTimer::timeout,
            button1, &Button::show);
    connect(timer2, &QTimer::timeout,
            [&]()->void{timer1->start();timer2->stop();});

    timer1->start();
}


Button::Button()
    : QPushButton() {}

Button::Button(QString label, QWidget *parent)
    : QPushButton(parent)
{
    setText(label);
}

Button::~Button() {}

void Button::setGeometry(int x, int y, int width, int height)
{
    QPushButton::setGeometry(x, y, width, height);
    init_x = x;
    init_y = y;
}

// void Button::hide()
// {
//     move(init_x + 1000, init_y + 1000);
// }

// void Button::show()
// {
//     move(init_x, init_y);
// }

// void Button::show(QString label)
// {
//     setText(label);
//     move(init_x, init_y);
// }
