/*
@ Name: Andres Nowak
@ Date: Tue May 19 20:26:26 CDT 2020
*/

#include "../headers/Game.hpp"
#include "../headers/Automatic.hpp"
#include "../headers/Manual.hpp"

#include <iostream>

int main()
{
    Game *game;

    game = new Automatic(30, 3, 3, 3, 4, 3, 20);

    game->start();
}
