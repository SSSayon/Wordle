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
    // QString s = "apple";
    // qDebug() << s.at(0);

    // int i = 12;
    // QString word = "apple";
    // QString word_trimmed = "";
    // for (int j = 0; j < 5; j++)
    //     if (((i >> (4-j)) & 1) == 1)
    //         word_trimmed += word[j];
    // qDebug() << word_trimmed;

    // WordDataSet wordDataSet = WordDataSet();
    // qDebug() << wordDataSet.ans_word;
    // qDebug() << wordDataSet.isValid("apple");

    a.exec();
    // qDebug() << game->gameStatus.guessed_words;
    return 0;
}
