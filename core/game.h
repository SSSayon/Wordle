#ifndef GAME_H
#define GAME_H

#include "game_status.h"

class Game
{
public:
    Game() {}
    ~Game() {}

    GameStatus gameStatus = GameStatus();

    int handleKeyPress(const QString &keyText);
    int handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid but hint unused, 3: word valid then enter
    int handleBackspace();

    QStringList _getValidWords();

private:
    void _cmpWord();
    int _isValidWord(const QString &word); // 1: not valid, 2: valid but not use all hints, 3: valid
    
};

#endif // GAME_H
