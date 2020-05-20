#include "Cell.hpp"
#include <string>

class Snake : public Cell
{
private:
    const std::string LOGO = "S";

    int tail_position_;
    int head_position_;

    const static int size_ = 3;

public:
    Snake(int position)
    {
        tail_position_ = position;
        head_position_ = position - size_;

        std::pair<int, int> positions = {tail_position_, head_position_};

        setTypeOfCell(LOGO);

        setPositionCell(positions);
    }

    void goDown(int &position)
    {
        position = tail_position_;
    }
};