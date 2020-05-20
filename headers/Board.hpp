#include "Cell.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    int size_;

    std::vector<std::shared_ptr<Cell>> cells_;

    std::unordered_map<std::string, int> amount_of_cells = {{"ladder", 0}, {"normal", 0}, {"snake", 0}};

    void createBoard();

public:
    Board(int size);
    Board();

    friend std::ostream &operator<<(std::ostream &output, const Board &board);

    std::shared_ptr<Cell> cellToChose(int &position);

    std::vector<std::shared_ptr<Cell>> getCells();
};

#endif