#include <utility>

#include "../headers/Cell.hpp"

void Cell::addPlayerToCell(Player &player)
{
    player_ = &player;
}

void Cell::deletePlayerFromCell()
{
    player_ = NULL; // maybe theres a better way to do this
}

Player *Cell::getPlayer()
{
    return player_;
}