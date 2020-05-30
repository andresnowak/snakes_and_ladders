/*
@ Name: Andres Nowak
@ Date: Tue May 19 20:26:26 CDT 2020
*/

#include "../headers/Game.hpp"
#include "../headers/Automatic.hpp"
#include "../headers/Manual.hpp"

#include <iostream>
#include <string>
#include <vector>

void start_game(std::vector<int> &game_info, std::string &game_type)
{
    Game *game;

    if (game_type == "M" or game_type == "m")
    {
        game = new Manual(game_info[0], game_info[1], game_info[2], game_info[3], game_info[4], game_info[5], game_info[6]);
    }
    else if (game_type == "A" or game_type == "a")
    {
        game = new Automatic(game_info[0], game_info[1], game_info[2], game_info[3], game_info[4], game_info[5], game_info[6]);
    }

    game->start();
}

void menu()
{
    std::vector<int> game_info(6, 0);

    std::string game_type;

    std::cout << "How many tiles you want: " << std::endl;
    std::cin >> game_info[0];

    std::cout << "How many snakes you want: " << std::endl;
    std::cin >> game_info[1];

    std::cout << "How many ladders you want: " << std::endl;
    std::cin >> game_info[2];

    std::cout << "How much reward you want: " << std::endl;
    std::cin >> game_info[3];

    std::cout << "How much penalty you want: " << std::endl;
    std::cin >> game_info[4];

    std::cout << "How many players are going to play: " << std::endl;
    std::cin >> game_info[5];

    std::cout << "What is the limit of turns you want: " << std::endl;
    std::cin >> game_info[6];

    std::cout << "Do you want the game to be automatic or manual: " << std::endl;
    std::cin >> game_type;

    start_game(game_info, game_type);
}

int main()
{
    menu();
}
