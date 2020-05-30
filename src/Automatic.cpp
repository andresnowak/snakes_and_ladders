#include "../headers/Automatic.hpp"

#include <chrono>
#include <thread>

Automatic::Automatic(int tiles, int number_snakes, int number_ladders, int penalty, int reward, int number_players, int turns) : Game(tiles, number_snakes, number_ladders, penalty, reward, number_players, turns)
{
    board_ = getBoard();
    players_ = getPlayers();
    dice_ = getDice();
}

void Automatic::start()
{
    std::cout << *board_ << std::endl;

    std::cout << "Press C to start game, or E to end the game:" << std::endl;

    choseOption();

    play();
}

void Automatic::play()
{
    std::vector<std::shared_ptr<Cell>> board_cells = board_->getCells();

    int turn = 1;

    while (true)
    {
        numberOfTurnsExceeded(turn);

        int dice_throw = dice_->roll();

        Player *player = &players_->front();

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

        std::cout << *board_ << std::endl;

        printGame(player_number, player_position, turn, cell, dice_throw, current_position);

        playerHasWon(player_won, player_number);

        turn++;

        players_->pop();
        players_->push(*player);

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sleep multiplatform
    }

    end(0);
}