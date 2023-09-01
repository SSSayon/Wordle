#include "gui/mainwindow.h"
#include "gui/input_window.h"
#include "gui/keyboard_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // Window1 w1(&w);
    // w1.show();
    InputWindow w2(&w);
    w2.show();
    KeyboardWindow w3(&w);
    w3.show();
    return a.exec();
}
