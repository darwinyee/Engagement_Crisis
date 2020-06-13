/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Game class codes.  It creates and handles the game
                 execution.
*******************************************************************************/

#include "Game.hpp"


//constructor
Game::Game() {

     //create the user character
     user1 = new MainCharacter();

     //create the map
     map1 = new SiteMap(user1);

     //display the introduction
     Introduction();

}



//private helper function
void Game::Introduction() {

     cout << endl << "PROLOGUE:" <<  endl;
     cout << endl << "\tToday is your big day!! You planned to propose to your long time girl of your dream!" << endl;
     cout << endl << "\tWith the restaurant and everything prepared, you were going to buy \n\tthe flower, the suit, and the engagement ring"
          << " once you received your paycheck today.  \n\tHowever, you were too nervous and lost your paycheck!!"
          << endl << "\tYou decided to go to the mall and buy the items within the time limit!"
          << endl << "\tWith $1200 and 120 mins left, will you be able to achieve the impossible?" << endl << endl;

     string userIn = "";
     do {
          cout << ">>>" << user1->userName() << ", Are you ready? (y/n) ";
          userIn = getYesOrNo();
          
     } while (userIn != "y");

}



//This function starts the game
void Game::StartGame() {

     bool endGame = false;

     while (!endGame) {

          user1->CurrentLoc()->SpecialAction();
          
          user1->PrintCharacterInfo();

          endGame = user1->CharacterGameStatus();

          if (!endGame) {
               map1->PrintMap();

               user1->Move();
          }

     }

}


//destructor
Game::~Game() {

     delete map1;
     delete user1;

}