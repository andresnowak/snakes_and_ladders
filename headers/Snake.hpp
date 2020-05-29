#include "Cell.hpp"
#include <string>

class Snake : public Cell
{
private:
    const std::string LOGO = "S";

    int tail_position_;
    int head_position_;

    int penalty_;

    void setPositionCell(int position)
    {
        tail_position_ = position;
        head_position_ = position - penalty_;
    }

public:
    Snake(int amount_of_players, int position) : Cell(amount_of_players)
    {
        penalty_ = 3;

        setPositionCell(position);
    }

    Snake(int amount_of_players, int position, int penalty) : Cell(amount_of_players)
    {
        penalty_ = penalty;

        setPositionCell(position);
    }

    const std::string getTypeOfCell()
    {
        return LOGO;
    }

    void movePosition(int &position)
    {
        position = head_position_;
    }

    std::pair<int, int> getPositionCell()
    {
        return {tail_position_, head_position_};
    }
};