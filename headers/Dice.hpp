#include <stdlib.h>
#include <time.h>

class Dice
{
private:
    static const int SIZE_OF_DICE = 6;

public:
    Dice()
    {
        //srand(time(NULL));
    }

    int roll()
    {
        int roll_of_dice = rand() % SIZE_OF_DICE + 1;

        return roll_of_dice;
    }
};