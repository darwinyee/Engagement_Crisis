/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-26-2019
** Description:  This is a main function for the final project.  
*******************************************************************************/

#include "Menu.hpp"
#include "InputValidation2.hpp"
#include "Game.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

int main() {

     // set the random seed
     srand((unsigned int)(time(0)));

     //variable for storing user's selection
     int userOption = 0;

     //display the header
     DisplayHeader("Final Project: A Text-based Game");


     //a do-while loop for the menu
     do {

          //display the option
          DisplayOptions();

          //get user's selection
          cout << ">>>";
          userOption = std::stoi(getValidInput("1|2"));

          if (userOption == 1) {

               //create a STLqueueTest object
               Game game1;

               //perform the simulation
               game1.StartGame();
          }   
          
     } while (userOption != 2);


     cout << "Thanks for using this program!" << endl;

     return 0;

}