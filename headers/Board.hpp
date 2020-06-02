#include "Cell.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    int size_;

    std::vector<std::shared_ptr<Cell>> cells_;

    std::unordered_set<int> positions_;

    int amount_of_players_;

    int amount_of_snakes_cells_;
    int amount_of_ladders_cells_;

    int penalty_;
    int reward_;

    std::unordered_map<std::string, int>
        amount_of_cells = {{"ladder", 0}, {"normal", 0}, {"snake", 0}};

    void createBoard();

public:
    Board(int, int, int, int, int, int);
    Board();

    friend std::ostream &operator<<(std::ostream &output, const Board &board);

    void createSnakesCells();
    void createLaddersCells();
    void createNormalCells();

    void movePositionInBoard(int &position_board);

    const std::string getTypeOfCell(int &position_board);

    void addPlayerToBoardCell(Player &player, int &position_board);

    void deletePlayerFromBoardCell(Player &player, int &position_board);

    int getSizeOfBoard();
};

#endif