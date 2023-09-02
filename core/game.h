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
    int handleEnter();
    int handleBackspace();

    void cmpWord();
};

#endif // GAME_H
