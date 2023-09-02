#include "game.h"

void Game::cmpWord()
{
    QString cur_word = gameStatus.cur_word;
    QString ans_word = gameStatus.ans_word;
    QString ans_word_deleted = "";
    int same_word[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
        if (cur_word[i] == ans_word[i])
            same_word[i] = 1;
        else
            ans_word_deleted += ans_word[i];

    for (int i = 0; i < 5; i++)
        if (same_word[i] == 0)
            if (ans_word_deleted.contains(cur_word[i]))
            {
                if (gameStatus.letter_color[cur_word[i].toLatin1() - 'a'] != Cell::Color::green)
                    gameStatus.letter_color[cur_word[i].toLatin1() - 'a'] = Cell::Color::yellow;
                gameStatus.cur_word_color[i] = Cell::Color::yellow;
                int pos = ans_word_deleted.indexOf(cur_word[i]);
                ans_word_deleted.remove(pos, 1);
            }
            else
            {
                if (gameStatus.letter_color[cur_word[i].toLatin1() - 'a'] == Cell::Color::gray)
                    gameStatus.letter_color[cur_word[i].toLatin1() - 'a'] = Cell::Color::darkGray;
                gameStatus.cur_word_color[i] = Cell::Color::darkGray;
            }
    for (int i = 0; i < 5; i++)
        if (same_word[i] == 1)
        {
            gameStatus.letter_color[cur_word[i].toLatin1() - 'a'] = Cell::Color::green;
            gameStatus.cur_word_color[i] = Cell::Color::green;
        }
}

int Game::handleKeyPress(const QString &keyText)
{
    int signal = 0; // 0: do nothing, 1: add letter
    if (gameStatus.is_game_over) return signal;
    if (gameStatus.cur_col == 4) return signal;

    signal = 1;
    gameStatus.cur_word += keyText;
    gameStatus.cur_word_color[gameStatus.cur_col + 1] = Cell::Color::black;
    gameStatus.cur_col++;
    return signal;
}

int Game::handleBackspace()
{
    int signal = 0; // 0: do nothing, 1: delete letter
    if (gameStatus.is_game_over) return signal;
    if (gameStatus.cur_col == 0) return signal;

    signal = 1;
    gameStatus.cur_word_color[gameStatus.cur_col] = Cell::Color::gray;
    gameStatus.cur_word.remove(gameStatus.cur_col, 1);
    gameStatus.cur_col--;
    return signal;
}

int Game::handleEnter()
{
    int signal = 0; // 0: do nothing, 1: word not valid, 2: word valid then enter
    if (gameStatus.is_game_over) return signal;
    if (gameStatus.cur_col < 5) return signal;

    signal = 1;
    if (!gameStatus.wordSet.isValid(gameStatus.cur_word)) return signal;

    signal = 2;
    if (gameStatus.cur_row == 5)
    {
        if (gameStatus.cur_word == gameStatus.ans_word)
        {
            gameStatus.is_game_won = true;
            gameStatus.is_game_over = true;
        }
        else
        {
            gameStatus.is_game_over = true;
        }
    }
    else
    {
        gameStatus.guessed_words->append(gameStatus.cur_word);
        gameStatus.cur_row++;
        gameStatus.cur_col = 0;
        gameStatus.cur_word = "";
        for (int i = 0; i < 5; i++) gameStatus.cur_word_color[i] = Cell::Color::gray;
    }
    return signal;
}
