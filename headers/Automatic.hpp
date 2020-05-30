#include "Game.hpp"
#include "Board.hpp"

#ifndef AUTOMATIC_H
#define AUTOMATIC_H

class Automatic : public Game
{
private:
    Board *board_;
    Dice *dice_;

    std::queue<Player> *players_;

    void play();

public:
    Automatic(int, int, int, int, int, int, int);

    void start();
};

#endif