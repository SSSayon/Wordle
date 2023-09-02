#include "gui/mainwindow.h"
#include "gui/input_window.h"
#include "gui/keyboard_window.h"
#include "core/hash.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    WordValidator wordValidator;

    return a.exec();
}
