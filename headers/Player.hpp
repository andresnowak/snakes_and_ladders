#include <utility>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int player_number_;
    int player_position_ = 1;

public:
    Player(int player_number);

    std::pair<int, int> getPlayerInfo();

    void movePlayer(int position);
};

#endif