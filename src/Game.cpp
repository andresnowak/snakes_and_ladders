#include "../headers/Game.hpp"
#include "../headers/Cell.hpp"
#include "../headers/Player.hpp"

#include <stdlib.h>
#include <ctime>
#include <vector>
#include <memory>
#include <iostream>

Game::Game()
{
    srand(time(NULL)); //only initialize once at the start of the game

    createPlayers(2);
}

void Game::start()
{
    board_ = Board();

    std::cout << board_ << std::endl;

    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl;

    choseOption();

    play();
}

void Game::play()
{
    std::vector<std::shared_ptr<Cell>> board_cells = board_.getCells();

    int turn = 1;

    while (true)
    {
        numberOfTurnsExceeded(turn);

        int dice_throw = dice_.roll();

        Player *player = &players_.front();

        std::pair<int, int> player_info = player->getPlayerInfo();

        int player_position = player_info.second;
        int player_number = player_info.first;

        deletePlayerFromBoard(player_position, *player);

        int current_position = dice_throw + player_position;

        bool player_won = checkPlayerHasWon(current_position);

        if (player_won)
        {
            current_position = board_cells.size();
        }

        Cell *cell = board_cells[current_position - 1].get();

        cell->movePosition(current_position);

        player->movePlayer(current_position);

        addPlayerToBoard(player, current_position);

        std::cout << board_ << std::endl;

        printGame(player_number, player_position, turn, cell, dice_throw, current_position);

        playerHasWon(player_won, player_number);

        turn++;

        choseOption();

        players_.pop();
        players_.push(*player);
    }

    end(0);
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

void Game::printGame(int &player_number, int &player_position, int &turn, Cell *cell, int &dice_throw, int &final_position)
{
    std::string type_of_cell = cell->getTypeOfCell();

    std::cout << turn << " " << player_number << " " << player_position << " "
              << dice_throw << " " << type_of_cell << " " << final_position << std::endl;
}

bool Game::checkPlayerHasWon(int position)
{
    if (position >= board_.getCells().size())
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

        // addPlayerToBoard(player, 0);
    }
}

void Game::addPlayerToBoard(Player *player, int position)
{
    board_.getCells()[position - 1].get()->addPlayerToCell(*player);
}

void Game::deletePlayerFromBoard(int position, Player &player)
{
    board_.getCells()[position - 1].get()->deletePlayerFromCell(player);
}