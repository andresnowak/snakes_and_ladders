#include "Cell.hpp"
#include <string>

class Normal : public Cell
{
private:
    const std::string LOGO = "N";

    int cell_position;

public:
    Normal(int start_position)
    {
        cell_position = start_position;

        std::pair<int, int> positions = {start_position, NULL};

        setTypeOfCell(LOGO);

        setPositionCell(positions);
    }
};