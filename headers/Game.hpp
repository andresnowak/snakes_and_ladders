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

    const int static limit_of_turns_ = 20;

    std::queue<Player> players_;

    void play();
    void end(int ending);

    std::string getInput();

    void continueGame();
    void choseOption();

    void printGame(int &player_number, int &player_position, int &turn, Cell *cell, int &dice_throw, int &final_position);

    bool checkPlayerHasWon(int position);

    void createPlayers(int amount_of_players);

    void playerHasWon(bool &won, int &player_number);

    void numberOfTurnsExceeded(int &turns);

    void addPlayerToBoard(Player *player, int position);
    void deletePlayerFromBoard(int position);

public:
    Game();

    void start();
};

#endif