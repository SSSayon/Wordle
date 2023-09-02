#include "gui/mainwindow.h"
#include "gui/input_window.h"
#include "gui/keyboard_window.h"
#include "core/game.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game();
    MainWindow mainWindow(nullptr, game);
    mainWindow.show();
    // game.gameStatus.ans_word = "craae";
    // game.gameStatus.cur_word = "aaaea";
    // game.cmpWord();
    // for (int i = 0; i < 5; i++)
    // {
    //     if (game.gameStatus.cur_word_color[i] == Cell::Color::green)
    //         qDebug() << "green";
    //     else if (game.gameStatus.cur_word_color[i] == Cell::Color::yellow)
    //         qDebug() << "yellow";
    //     else if (game.gameStatus.cur_word_color[i] == Cell::Color::darkGray)
    //         qDebug() << "darkGray";
    //     else
    //         qDebug() << "gray";
    // }   
    return a.exec();
}
