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

    int turns = 1;
    while (true)
    {
        Game::play(turns, board_size);
        choseOption();
    }
}