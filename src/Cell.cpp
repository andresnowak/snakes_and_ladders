#include <utility>

#include "../headers/Cell.hpp"

Cell::Cell(int amount_of_players)
{
    players_ = std::vector<Player *>(amount_of_players, NULL);
}

void Cell::addPlayerToCell(Player &player)
{
    players_[player.getPlayerInfo().first - 1] = &player;
}

void Cell::deletePlayerFromCell(Player &player)
{
    players_[player.getPlayerInfo().first - 1] = NULL;
}

std::vector<Player *> Cell::getPlayers()
{
    return players_;
}

std::ostream &operator<<(std::ostream &output, Cell *cell)
{
    output << cell->getTypeOfCell();

    for (auto x : cell->getPlayers())
    {
        if (x != NULL)
        {
            int player_number = x->getPlayerInfo().first;

            output << player_number;
        }
        else
        {
            output << " ";
        }
    }

    return output;
}