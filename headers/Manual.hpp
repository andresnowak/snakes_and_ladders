#include "Game.hpp"
#include "Board.hpp"

#include <functional>

#ifndef MANUAL_H
#define MANUAL_H

class Manual : public Game
{
private:
    Board *board_;

    void play()
    {
        int board_size = board_->getSizeOfBoard();

        int turns = 1;
        while (true)
        {
            Game::play(turns, board_size);
            choseOption();
        }
    }

public:
    Manual(int tiles, int number_snakes, int number_ladders, int penalty, int reward, int number_players, int turns) : Game(tiles, number_snakes, number_ladders, penalty, reward, number_players, turns)
    {
        board_ = getBoard();
    }

    void start()
    {
        std::cout << *board_ << std::endl;

        std::cout << "Press C to continue next turn, or E to end the game:" << std::endl;

        choseOption();

        play();
    }
};

#endif