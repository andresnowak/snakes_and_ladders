#include "Game.hpp"
#include "Board.hpp"

#ifndef MANUAL_H
#define MANUAL_H

class Manual : public Game
{
private:
    Board *board_;
    Dice *dice_;

    std::queue<Player> *players_;

    void play();

public:
    Manual(int, int, int, int, int, int, int);

    void start();
};

#endif