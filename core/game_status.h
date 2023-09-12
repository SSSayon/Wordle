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
    int letter_occurrence[26]; // min occurrence of each letter (yellow & green)
    bool has_fixed[26]; // when a letter is darkGray, its occurrence is entirely fixed
    int impossible_position[26]; // 0~31(2^5-1), in each bit, 1 means impossible
    QChar green_letter[5]; // green letters
    bool has_game_started = false;
    bool is_game_over = false;
    bool is_game_won = false;
    int game_mode = 1; // 0: normal, 1: hard

    GameStatus() 
    {
        wordDataSet = WordDataSet();
        ans_word = wordDataSet.generateRandomAnswer();
        for (int i = 0; i < 5; i++) cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 5; i++) prev_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_occurrence[i] = 0;
        for (int i = 0; i < 26; i++) has_fixed[i] = false;
        for (int i = 0; i < 26; i++) impossible_position[i] = 0;
        for (int i = 0; i < 5; i++) green_letter[i] = ' ';
    }
    ~GameStatus() {}
};

#endif // GAME_STATUS_H
