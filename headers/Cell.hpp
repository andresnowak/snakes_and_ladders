#include <utility>
#include <functional>
#include <experimental/optional>

#include "Player.hpp"

#define optional experimental::optional

#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    std::optional<Player> player_;

    std::string type_of_cell_;

    std::pair<int, int> position_cell_ = {NULL, NULL};

public:
    void addPlayerToCell(Player player);

    std::pair<int, int> getPositionCell();

    std::optional<Player> getPlayer();

    void setPositionCell(std::pair<int, int> position_cell);
    void setTypeOfCell(std::string logo);

    void movePosition(int &position);

    std::string getTypeOfCell();
};

#endif