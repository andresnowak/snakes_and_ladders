#include <utility>
#include <functional>
#include <vector>
#include <iostream>

#include "Player.hpp"

#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    std::vector<Player *> players_;

    std::vector<Player *> getPlayers();

public:
    Cell(int);

    void addPlayerToCell(Player &player);

    virtual std::pair<int, int> getPositionCell() = 0;

    virtual void movePosition(int &position) = 0;

    virtual const std::string getTypeOfCell() = 0;

    void deletePlayerFromCell(Player &player);

    friend std::ostream &
    operator<<(std::ostream &output, Cell &cell);
};

#endif