#include "Cell.hpp"
#include <string>

class Ladder : public Cell
{
private:
    const std::string LOGO = "L";

    int start_position_;
    int end_position_;

    const static int size_ = 3;

public:
    Ladder(int position)
    {
        start_position_ = position;
        end_position_ = position + size_;

        std::pair<int, int> positions = {start_position_, end_position_};

        setTypeOfCell(LOGO);

        setPositionCell(positions);
    }

    void goUp(int &position)
    {
        position = end_position_;
    }
};