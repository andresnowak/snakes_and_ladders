#include "../headers/Board.hpp"
#include "../headers/Dice.hpp"

#include <queue>
#include <string>
#include <utility>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Board board_;
    Dice dice_;

    const int static limit_of_turns = 20;

    std::queue<Player> players_;

    void play(std::vector<std::shared_ptr<Cell>> board_cells);
    void end(int ending);

    std::string getInput();

    void continueGame();
    void choseOption();

    void printGame(std::pair<int, int> &player_info, int &turn, Cell *cell, int &dice_throw, int &final_position);

    bool checkPlayerHasWon(int position);

    void createPlayers(int amount_of_players);

    void playerHasWon(bool &won, int &player_number);

    void numberOfTurnsExceeded(int &turns);

public:
    Game();

    void start();
};

#endif