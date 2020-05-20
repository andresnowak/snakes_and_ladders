#include "../headers/Player.hpp"

Player::Player(int player_number)
{
    player_number_ = player_number;
}

std::pair<int, int> Player::getPlayerInfo()
{
    return {player_number_, player_position_};
}

void Player::movePlayer(int position)
{
    player_position_ = position;
}