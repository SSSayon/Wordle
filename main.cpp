#include "gui/mainwindow.h"
#include "gui/input_window.h"
#include "gui/keyboard_window.h"
#include "core/game.h"
#include "core/load_data.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game();
    // qDebug() << game->gameStatus.ans_word;
    MainWindow mainWindow(nullptr, game);
    mainWindow.show();

    a.exec();
    // qDebug() << game->gameStatus.guessed_words;
    // qDebug() << game->gameStatus.ans_word;

    // qDebug() << QStringList(game->gameStatus.wordDataSet.validWordBucket[28].values("app"));

    // game->gameStatus.green_letter[1] = 'a';
    // game->gameStatus.green_letter[2] = 'p';
    // qDebug() << game->_getValidWords();
    return 0;
}
