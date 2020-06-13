/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Game class header.  It creates and handles the game
                 execution.
*******************************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include "SiteMap.hpp"
#include "MainCharacter.hpp"


using std::string;
using std::cout;
using std::endl;

class Game {

private:

     //A pointer variable for the character
     MainCharacter* user1;

     //A pointer variable for the map
     SiteMap* map1;

     //private helper function
     void Introduction();

public:

     //constructor
     Game();

     //This function starts the game
     void StartGame();

     //destructor
     ~Game();

};

#endif 