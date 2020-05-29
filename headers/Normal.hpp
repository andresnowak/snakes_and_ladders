#include "Cell.hpp"
#include <string>

class Normal : public Cell
{
private:
    const std::string LOGO = "N";

    int cell_position;

    void setPositionCell(int position)
    {
        cell_position = position;
    }

public:
    Normal(int amount_of_players, int start_position) : Cell(amount_of_players)
    {
        setPositionCell(start_position);
    }

    void movePosition(int &position)
    {
        position = cell_position;
    }

    const std::string getTypeOfCell()
    {
        return LOGO;
    }

    std::pair<int, int> getPositionCell()
    {
        return {cell_position, NULL};
    }
};