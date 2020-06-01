#include "../headers/Manual.hpp"

Manual::Manual(int tiles, int number_snakes, int number_ladders, int penalty, int reward, int number_players, int turns) : Game(tiles, number_snakes, number_ladders, penalty, reward, number_players, turns)
{
    board_ = getBoard();
    players_ = getPlayers();
    dice_ = getDice();
}

void Manual::start()
{
    std::cout << *board_ << std::endl;

    std::cout << "Press C to continue next turn, or E to end the game:" << std::endl;

    choseOption();

    play();
}

void Manual::play()
{
    int board_size = board_->getSizeOfBoard();

    int turn = 1;

    while (true)
    {
        numberOfTurnsExceeded(turn);

        int dice_throw = dice_->roll();

        Player *player = &players_->front();

        std::pair<int, int> player_info = player->getPlayerInfo();

        int player_position = player_info.second;
        int player_number = player_info.first;

        board_->deletePlayerFromBoardCell(*player, player_position);

        int current_position = dice_throw + player_position;

        bool player_won = checkPlayerHasWon(current_position);

        if (player_won)
        {
            current_position = board_size;
        }

        std::string cell_type = board_->getTypeOfCell(current_position);

        board_->movePositionInBoard(current_position);

        player->movePlayer(current_position);

        board_->addPlayerToBoardCell(*player, current_position);

        std::cout << *board_ << std::endl;

        printGame(player_number, player_position, turn, cell_type, dice_throw, current_position);

        playerHasWon(player_won, player_number);

        turn++;

        choseOption();

        players_->pop();
        players_->push(*player);
    }

    end(0);
}