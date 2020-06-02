#include "../headers/Board.hpp"
#include "../headers/Normal.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Ladder.hpp"

#include <iostream>

Board::Board()
{
    size_ = 30;

    cells_ = std::vector<std::shared_ptr<Cell>>(size_, NULL);

    amount_of_players_ = 3;

    amount_of_snakes_cells_ = 4;
    amount_of_ladders_cells_ = 5;

    penalty_ = 4;
    reward_ = 5;

    createBoard();
}

Board::Board(int size, int amount_snakes, int amount_ladders, int penalty, int reward, int amount_of_players)
{
    size_ = size;

    cells_ = std::vector<std::shared_ptr<Cell>>(size_, NULL);

    amount_of_players_ = amount_of_players;

    amount_of_snakes_cells_ = amount_snakes;
    amount_of_ladders_cells_ = amount_ladders;

    penalty_ = penalty;
    reward_ = reward;

    createBoard();
}

void Board::createSnakesCells()
{
    int count = 0;

    while (count < amount_of_snakes_cells_)
    {
        int position = rand() % (size_ - 1); // we dont want the last cell to be a snake

        if (cells_[position] == NULL)
        {
            std::shared_ptr<Snake> snake(new Snake(amount_of_players_, position + 1, penalty_));

            int end_position = snake.get()->getPositionCell().second;

            if (end_position > 0 and cells_[end_position - 1] == NULL)
            {
                amount_of_cells["snake"]++;

                cells_[position] = snake;
                cells_[end_position - 1] = snake;

                positions_.insert(position + 1);

                count++;
            }
        }
    }
}

void Board::createLaddersCells()
{
    int count = 0;

    while (count < amount_of_ladders_cells_)
    {
        int position = rand() % size_;

        if (cells_[position] == NULL)
        {
            std::shared_ptr<Ladder> ladder(new Ladder(amount_of_players_, position + 1, reward_));

            int end_position = ladder.get()->getPositionCell().second;

            if (end_position <= size_ and cells_[end_position - 1] == NULL)
            {
                amount_of_cells["ladder"]++;

                cells_[position] = ladder;
                cells_[end_position - 1] = ladder;

                positions_.insert(position + 1);

                count++;
            }
        }
    }
}

void Board::createNormalCells()
{
    int count = 0;

    for (int position = 0; position < size_; position++)
    {
        if (cells_[position] == NULL)
        {
            std::shared_ptr<Normal> normal(new Normal(amount_of_players_, position + 1));

            cells_[position] = normal;
        }
    }
}

void Board::createBoard()
{
    createSnakesCells();
    createLaddersCells();
    createNormalCells();
}

std::vector<std::shared_ptr<Cell>> Board::getCells()
{
    return cells_;
}

std::ostream &operator<<(std::ostream &output, const Board &board)
{
    int count = 1;

    for (int position = 0; position < board.size_; position++)
    {
        Cell *cell_actual = board.cells_[position].get();

        output << cell_actual << " ";

        if (count == 6)
        {
            output << '\n';

            count = 0;
        }

        count++;
    }

    return output;
}

void Board::movePositionInBoard(int &position_board)
{
    cells_[position_board - 1].get()->movePosition(position_board);
}

const std::string Board::getTypeOfCell(int &position_board)
{
    return cells_[position_board - 1].get()->getTypeOfCell();
}

void Board::addPlayerToBoardCell(Player &player, int &position_board)
{
    cells_[position_board - 1].get()->addPlayerToCell(player);
}

void Board::deletePlayerFromBoardCell(Player &player, int &position_board)
{
    cells_[position_board - 1].get()->deletePlayerFromCell(player);
}

int Board::getSizeOfBoard()
{
    return cells_.size();
}