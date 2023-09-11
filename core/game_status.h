#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "load_data.h"
#include "../gui/cell.h"
#include <QStringList> 

struct GameStatus
{
    WordDataSet wordDataSet;
    QString ans_word;
    int cur_row = 0;
    int cur_col = 0;
    QString cur_word = "";
    Cell::Color cur_word_color[5];
    Cell::Color prev_word_color[5];
    QStringList guessed_words;
    Cell::Color letter_color[26];
    int letter_occurrence[26]; // count yellow but no green letters, -1: not known yet, 0: absent
    QChar green_letter[5]; // green letters
    bool is_game_over = false;
    bool is_game_won = false;
    int game_mode = 0; // 0: normal, 1: hard

    GameStatus() 
    {
        wordDataSet = WordDataSet();
        ans_word = wordDataSet.generateRandomAnswer();
        for (int i = 0; i < 5; i++) cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 5; i++) prev_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_occurrence[i] = -1;
        for (int i = 0; i < 5; i++) green_letter[i] = ' ';
    }
    ~GameStatus() {}
};

#endif // GAME_STATUS_H
