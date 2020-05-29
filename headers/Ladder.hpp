#include "Cell.hpp"
#include <string>

class Ladder : public Cell
{
private:
    const std::string LOGO = "L";

    int start_position_;
    int end_position_;

    int reward_;

    void setPositionCell(int position)
    {
        start_position_ = position;
        end_position_ = position + reward_;
    }

public:
    Ladder(int amount_of_players, int position) : Cell(amount_of_players)
    {
        reward_ = 3;

        setPositionCell(position);
    }

    Ladder(int amount_of_players, int position, int reward) : Cell(amount_of_players)
    {
        reward_ = reward;

        setPositionCell(position);
    }

    void movePosition(int &position)
    {
        position = end_position_;
    }

    std::pair<int, int> getPositionCell()
    {
        return {start_position_, end_position_};
    }

    const std::string getTypeOfCell()
    {
        return LOGO;
    }
};