#include "Game.hpp"
#include "Board.hpp"

#include <chrono>
#include <thread>

#ifndef AUTOMATIC_H
#define AUTOMATIC_H

class Automatic : public Game
{
private:
    Board *board_;
    Dice *dice_;

    std::queue<Player> *players_;

    void play()
    {
        int board_size = board_->getSizeOfBoard();

        int turns = 1;
        while (true)
        {
            Game::play(turns, board_size);
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sleep multiplatform
        }
    };

public:
    Automatic(int tiles, int number_snakes, int number_ladders, int penalty, int reward, int number_players, int turns) : Game(tiles, number_snakes, number_ladders, penalty, reward, number_players, turns)
    {
        board_ = getBoard();
        players_ = getPlayers();
        dice_ = getDice();
    }

    void start()
    {
        std::cout << *board_ << std::endl;

        std::cout << "Press C to start game, or E to end the game:" << std::endl;

        choseOption();

        play();
    }
};

#endif