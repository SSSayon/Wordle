#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "hash.h"
#include "../gui/cell.h"
#include <QStringList> 

struct GameStatus
{
    QString ans_word = "piano";
    WordSet wordSet = WordSet();
    int cur_row = 0;
    int cur_col = 0;
    QString cur_word = "";
    Cell::Color cur_word_color[5];
    Cell::Color prev_word_color[5];
    QStringList *guessed_words = new QStringList();
    Cell::Color letter_color[26];
    bool is_game_over = false;
    bool is_game_won = false;

    GameStatus() 
    {
        for (int i = 0; i < 5; i++) cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_color[i] = Cell::Color::gray;
    }
    ~GameStatus() { delete guessed_words; }
};

#endif // GAME_STATUS_H
