#include "Cell.hpp"
#include <string>

class Ladder : public Cell
{
private:
    const std::string LOGO = "L";

    int start_position_;
    int end_position_;

    const static int size_ = 3;

    void setPositionCell(int position)
    {
        start_position_ = position;
        end_position_ = position + size_;
    }

public:
    Ladder(int position)
    {
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