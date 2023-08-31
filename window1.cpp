#include <window1.h>

Window1::Window1(QWidget *parent)
    : QWidget(parent)
{
    // setWindowTitle("Window 1");
    setFixedSize(200, 150);
    createButton();
}

Window1::~Window1()
{
    delete button1;
    delete button2;
}

void Window1::createButton()
{
    button1 = new QPushButton("Button1", this);
    button1->setGeometry(100, 50, 80, 30);

    button2 = new QPushButton();
    button2->setText("Button2");
    button2->setParent(this);
    button2->setGeometry(100, 100, 80, 30);
}
