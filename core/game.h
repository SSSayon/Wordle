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

private:
    void _cmpWord();
    bool _isValidWord(const QString &word);
    QStringList _getValidWords(const QString &word);
};

#endif // GAME_H
