#include "Cell.hpp"
#include <string>

class Snake : public Cell
{
private:
    const std::string LOGO = "S";

    int tail_position_;
    int head_position_;

    const static int size_ = 3;

    void setPositionCell(int position)
    {
        tail_position_ = position;
        head_position_ = position - size_;
    }

public:
    Snake(int position)
    {
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