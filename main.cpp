#include "mainwindow.h"
#include "window1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Window1 w1(&w);
    w1.show();
    return a.exec();
}
