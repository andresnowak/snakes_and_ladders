#include "../headers/Game.hpp"
#include "../headers/Cell.hpp"
#include "../headers/Player.hpp"

#include <stdlib.h>
#include <ctime>
#include <vector>
#include <memory>
#include <iostream>

Game::Game(int tiles, int number_snakes, int number_ladders, int penalty, int reward, int number_players, int turns)
{
    srand(time(NULL)); //only initialize once at the start of the game

    board_ = Board(tiles, number_snakes, number_ladders, penalty, reward, number_players);

    limit_of_turns_ = turns;

    createPlayers(number_players);
}

void Game::end(int ending)
{
    if (ending == 1)
    {
        std::cout << "Thanks for playing!!!" << std::endl;
    }
    else if (ending == 2)
    {
        std::cout << "The maximum number of turns has been reached..." << std::endl;
    }

    std::cout << '\n'
              << "--GAME OVER--" << '\n';

    exit(0);
}

void Game::choseOption()
{
    std::string option = getInput();

    if (option == "E")
    {
        end(1);
    }
    else if (option == "C")
    {
        return;
    }
    else
    {
        std::cout << "Invalid option, please press C to continue next turn or E to end the game" << std::endl;

        return choseOption();
    }
}

void Game::printGame(int &player_number, int &player_position, int &turn, std::string &cell_type, int &dice_throw, int &final_position)
{
    std::cout << turn << " " << player_number << " " << player_position << " "
              << dice_throw << " " << cell_type << " " << final_position << std::endl;
}

bool Game::checkPlayerHasWon(int position)
{
    if (position >= board_.getSizeOfBoard())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::playerHasWon(bool &won, int &player_number)
{
    if (won)
    {
        std::cout << "Player " << player_number << " is the winner!!!" << std::endl;

        end(0);
    }
}

void Game::numberOfTurnsExceeded(int &turns)
{
    if (turns > limit_of_turns_)
    {
        end(2);
    }
}

std::string Game::getInput()
{

    std::string option;

    std::cin >> option;

    return option;
}

void Game::createPlayers(int amount_of_players)
{
    for (int i = 1; i <= amount_of_players; i++)
    {
        Player player = Player(i);
        players_.push(player);
    }
}

Board *Game::getBoard()
{
    return &board_;
}

std::queue<Player> *Game::getPlayers()
{
    return &players_;
}

Dice *Game::getDice()
{
    return &dice_;
}

void Game::play(int &turn, int board_size)
{
    numberOfTurnsExceeded(turn);

    int dice_throw = dice_.roll();

    Player *player = &players_.front();

    std::pair<int, int> player_info = player->getPlayerInfo();

    int player_position = player_info.second;
    int player_number = player_info.first;

    board_.deletePlayerFromBoardCell(*player, player_position);

    int current_position = dice_throw + player_position;

    std::string cell_type = board_.getTypeOfCell(current_position);

    board_.movePositionInBoard(current_position);

    player->movePlayer(current_position);

    board_.addPlayerToBoardCell(*player, current_position);

    std::cout << board_ << std::endl;

    printGame(player_number, player_position, turn, cell_type, dice_throw, current_position);

    bool player_won = checkPlayerHasWon(current_position);

    playerHasWon(player_won, player_number);

    turn++;

    players_.pop();
    players_.push(*player);
}