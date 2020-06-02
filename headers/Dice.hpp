#include <stdlib.h>
#include <time.h>

#ifndef DICE_H
#define DICE_H

class Dice
{
private:
    static const int SIZE_OF_DICE = 6;

public:
    int roll()
    {
        int roll_of_dice = rand() % SIZE_OF_DICE + 1;

        return roll_of_dice;
    }
};

#endif