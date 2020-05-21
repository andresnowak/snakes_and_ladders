#include "../headers/Board.hpp"
#include "../headers/Normal.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Ladder.hpp"

#include <unordered_set>
#include <iostream>

Board::Board()
{
    size_ = 30;

    cells_ = std::vector<std::shared_ptr<Cell>>(size_);

    createBoard();
}

std::shared_ptr<Cell> Board::cellToChose(int &position)
{
    int cell = rand() % 3 + 1;

    if (cell == 1)
    {
        amount_of_cells["normal"]++;

        return std::shared_ptr<Normal>(new Normal(position));
    }
    else if (cell == 2 and position < size_ and amount_of_cells["ladder"] < 3)
    {
        std::shared_ptr<Ladder> ladder(new Ladder(position));

        if (ladder.get()->getPositionCell().second < size_)
        {
            amount_of_cells["ladder"]++;

            return ladder;
        }
    }
    else if (cell == 3 and position < size_ and amount_of_cells["snake"] < 3)
    {
        std::shared_ptr<Snake> snake(new Snake(position));

        if (snake.get()->getPositionCell().second > 0)
        {
            amount_of_cells["snake"]++;

            return snake;
        }
    }

    return cellToChose(position);
}

void Board::createBoard()
{
    std::unordered_set<int> positions;

    for (int position = 1; position <= size_; position++)
    {
        if (positions.count(position) == 0)
        {
            std::shared_ptr<Cell> cell = cellToChose(position);

            int end_position = cell.get()->getPositionCell().second;

            cells_[position - 1] = cell;

            if (end_position != 0)
            {
                cells_[end_position - 1] = cell;
            }

            positions.insert(cell.get()->getPositionCell().second);
        }

        positions.insert(position);
    }
}

std::vector<std::shared_ptr<Cell>> Board::getCells()
{
    return cells_;
}

std::ostream &operator<<(std::ostream &output, const Board &board)
{
}