#include <utility>
#include <functional>

#include "Player.hpp"

#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    Player *player_;

public:
    void addPlayerToCell(Player &player);

    virtual std::pair<int, int> getPositionCell() = 0;

    Player *getPlayer();

    virtual void movePosition(int &position) = 0;

    virtual const std::string getTypeOfCell() = 0;

    void deletePlayerFromCell();
};

#endif