#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "load_data.h"
#include "../gui/cell.h"
#include <QStringList> 

struct GameStatus
{
    WordDataSet wordDataSet;
    QString ans_word;
    int cur_row;
    int cur_col;
    QString cur_word = "";
    Cell::Color cur_word_color[5];
    Cell::Color prev_word_color[5];
    QStringList guessed_words;
    Cell::Color letter_color[26];
    int letter_occurrence[26]; // min occurrence of each letter (yellow & green)
    bool has_fixed[26]; // when a letter is darkGray, its occurrence is entirely fixed
    int impossible_position[26]; // 0~31(2^5-1), in each bit, 1 means impossible
    QChar green_letter[5]; // green letters
    bool has_game_started;
    bool is_game_over;
    bool is_game_won;
    int game_mode; // 0: normal, 1: hard

    GameStatus() 
    {
        wordDataSet = WordDataSet();
        resetGameStatus();
        game_mode = 0;
    }
    ~GameStatus() {}

    void resetGameStatus()
    {
        ans_word = wordDataSet.generateRandomAnswer();
        cur_row = 0;
        cur_col = 0;
        cur_word = "";
        for (int i = 0; i < 5; i++) cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 5; i++) prev_word_color[i] = Cell::Color::gray;
        guessed_words = QStringList();
        for (int i = 0; i < 26; i++) letter_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_occurrence[i] = 0;
        for (int i = 0; i < 26; i++) has_fixed[i] = false;
        for (int i = 0; i < 26; i++) impossible_position[i] = 0;
        for (int i = 0; i < 5; i++) green_letter[i] = ' ';
        has_game_started = false;
        is_game_over = false;
        is_game_won = false;
    }
};

#endif // GAME_STATUS_H
