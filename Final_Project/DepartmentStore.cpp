/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the DepartmentStore codes for the class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "DepartmentStore.hpp"


//nondefault Constructor
DepartmentStore::DepartmentStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "DepartmentStore";
     this->user1 = user1;
     specialEvent = true;

}



//execute the special action
void DepartmentStore::SpecialAction() {

     cout << string(60, '*');
     cout << endl << string(15, ' ') << "You are in the " + spaceName + "!" << endl;
     cout << string(60, '*');

     //two time variables to keep track of time spent in the store
     time_t inStore, outStore;
     time(&inStore);

     string userIn;
     do {
          cout << endl << "Options:";
          cout << endl << "\t1. Browse around the store." << endl;
          cout << "\t2. Leave the store. " << endl << endl;

          cout << ">>>What would you like to do? ";

          userIn = getValidInput("1|2");


          if (userIn == "1") {

               //give a hint
               HintEvents();
          }
          else if (userIn == "2") {
               //give some free items
               FreeItem();
          }

     } while (userIn != "2");
     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min

}

 

//function to select a random event
void DepartmentStore::HintEvents() {

     if (specialEvent) {
          //message prompt for the user
          cout << endl << "While in the store, you head to the Jewelry department to see \nif you can find the ring you want."
               << endl << ">>>A salesperson comes by offering to help. Do you need help? (y/n)" ;

          //if accept help, new information is provided
          if (getYesOrNo() == "y") {

               cout << endl << "The salesperson spent 10 mins trying to find the ring you want."
                    << endl << "However, none of them caught your eyes.\n"
                    << endl << "While disappointed, the salesperson suggested you check out the store website."
                    << endl << "And you finally found the one you want at a great price!\n"
                    << endl << "Since it was online only, you kindly asked for a printout with a price on, \nhoping to price match at the Jewelry store nearby." << endl;
               user1->AddItem("Ring Price Match Printout", false);
               user1->AdjustTime(-10);
               specialEvent = false;

          }
          else
               cout << "You kindly reject his help, knowing that you will be held by him for 10+ mins." << endl;
     }else
          cout << endl << "There was not much to do in the store." << endl;

}



//This function gives out free items, which may or may not be useful thoughout the game
void DepartmentStore::FreeItem() {

     cout << endl << "While leaving the store, you are stopped by an enthusiastic saleswoman..." << endl;
     cout << "She tells you the store was running sales on various items today!" << endl;
     cout << "You want to leave, but don't know how to reject her..." << endl;
     cout << "Konwing that you are eager to leave, she then offers you a free gift." << endl;
     cout << "You decided to take one so you can leave as soon as possible." << endl;
     cout << "Which item will you pick? (bandage, soap, notepad, gum, cup) ";
     string userPick = getValidInput("bandage|soap|notepad|gum|cup");

     user1->AddItem(userPick, false);         

}