#include <utility>

#include "../headers/Cell.hpp"

void Cell::addPlayerToCell(Player player)
{
    player_ = player;
}

std::pair<int, int> Cell::getPositionCell()
{
    return position_cell_;
}

std::optional<Player> Cell::getPlayer()
{
    return player_;
}

void Cell::setPositionCell(std::pair<int, int> position_cell)
{
    position_cell_ = position_cell;
}

void Cell::setTypeOfCell(std::string logo)
{
    type_of_cell_ = logo;
}

void Cell::movePosition(int &position)
{
    if (position_cell_.second != 0)
    {
        position = position_cell_.second;
    }
}

std::string Cell::getTypeOfCell()
{
    return type_of_cell_;
}