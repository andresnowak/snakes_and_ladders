#include "Board.hpp"
#include "Dice.hpp"

#include <queue>
#include <string>
#include <utility>

#include <queue>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Board board_;
    Dice dice_;

    int limit_of_turns_;

    std::queue<Player> players_;

protected:
    void end(int ending);

    std::string getInput();

    void choseOption();

    void printGame(int &player_number, int &player_position, int &turn, Cell *cell, int &dice_throw, int &final_position);

    bool checkPlayerHasWon(int position);

    void createPlayers(int amount_of_players);

    void playerHasWon(bool &won, int &player_number);

    void numberOfTurnsExceeded(int &turns);

    void addPlayerToBoard(Player *player, int position);
    void deletePlayerFromBoard(int position, Player &player);

    Board *getBoard();
    std::queue<Player> *getPlayers();
    Dice *getDice();

public:
    Game(int, int, int, int, int, int, int);

    virtual void start() = 0;
};

#endif