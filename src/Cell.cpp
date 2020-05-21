#include <utility>

#include "../headers/Cell.hpp"

void Cell::addPlayerToCell(Player player)
{
    player_ = player;
}

std::optional<Player> Cell::getPlayer()
{
    return player_;
}