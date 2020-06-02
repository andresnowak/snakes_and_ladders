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
#include <limits>
#include <ios>

void printErrorMessageMenu(std::string adjective, std::string type, int min, int max)
{
    std::cout << adjective << " of " << type << " is incorrect, remember it has to be between " << min << " and " << max << " try again:" << std::endl;
}

bool isSizeCorrect(int &object, int &min, int &max)
{
    if (object >= min and object <= max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getNumberSizeOfVariable(int &variable, std::string adjective, std::string type, int &min, int &max)
{
    std::cin >> variable;

    if (isSizeCorrect(variable, min, max))
    {
        return variable;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*because we add the value to a int we need to clear the buffer because it 
    enters in a loop because the buffer doesnt have anywhere to go because a 
    letter cant be an int*/

    printErrorMessageMenu(adjective, type, min, max);

    return getNumberSizeOfVariable(variable, adjective, type, min, max);
}

std::string getGameType()
{
    std::string game_type;
    std::cin >> game_type;

    if (game_type == "M" or game_type == "m" or game_type == "A" or game_type == "a")
    {
        return game_type;
    }

    std::cout << "The game type you inserted is incorrect, try again: " << std::endl;

    return getGameType();
}

void startGame(std::vector<int> &game_info, std::string &game_type)
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

    std::cout << "How many tiles do you want: " << std::endl;
    int min_tiles = 12;
    int max_tiles = 100;
    getNumberSizeOfVariable(game_info[0], "Size", "tiles", min_tiles, max_tiles);

    int min_snakes_ladders = 1;
    int max_snakes_ladders = game_info[0] / 6;

    int min_reward_penalty = 2;
    int max_reward_penalty = game_info[0] / 4;

    std::cout << "How many snakes do you want: " << std::endl;

    getNumberSizeOfVariable(game_info[1], "Number", "snakes", min_snakes_ladders, max_snakes_ladders);

    std::cout << "How many ladders do you want: " << std::endl;
    getNumberSizeOfVariable(game_info[2], "Number", "ladders", min_snakes_ladders, max_snakes_ladders);

    std::cout << "How big do you want the penalty to be: " << std::endl;
    getNumberSizeOfVariable(game_info[3], "Size", "penalty", min_reward_penalty, max_reward_penalty);

    std::cout << "How big do you want the reward to be: " << std::endl;
    getNumberSizeOfVariable(game_info[4], "Size", "reward", min_reward_penalty, max_reward_penalty);

    std::cout << "How many players are going to play: " << std::endl;
    int min_players = 2;
    int max_players = 6;
    getNumberSizeOfVariable(game_info[5], "Number", "players", min_players, max_players);

    std::cout << "What is the limit of turns that you want: " << std::endl;
    int min_turns = 10;
    int max_turns = INT32_MAX;
    getNumberSizeOfVariable(game_info[6], "Number", "turns", min_turns, max_turns);

    std::cout << "Do you want the game to be automatic or manual (A or M): " << std::endl;
    game_type = getGameType();

    startGame(game_info, game_type);
}

int main()
{
    menu();
}
