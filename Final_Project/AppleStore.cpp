/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the AppleStore codes for the AppleStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "AppleStore.hpp"


//nondefault Constructor
AppleStore::AppleStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "AppleStore";
     this->user1 = user1;
     specialEvent = true;

}



//execute the special action
void AppleStore::SpecialAction() {

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

     } while (userIn != "2");
     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent/5);       //every 5 seconds equal 1 min 

}



//function to select a random event
void AppleStore::HintEvents() {

     //message prompt for the user
     cout << endl << "A new iphone just came out!! The phone surely looks attractive, but the price is unreal..."
          << endl << "Who in the world would spend $2000 on a phone?!" << endl;

     //opportunity to buy a special toy
     if (specialEvent) {

          cout << endl << "Suddenly you remembered your 3-year old iphone would not receive message. \nA fix at the store would cost $100."
               << endl << "Do you want to fix it (y/n)? ";
          if (getYesOrNo() == "y") {
               if (user1->CheckMoney() >= 100) {
                    user1->AdjustMoney(-100);

                    cout << "It turned out to be a 1 min fix!!! \nYour girlfriend messaged you that she would be 30 min late because of traffic.\nDon't know if this is lucky or not..." << endl;
                    user1->AdjustTime(30);

                    //no more special event for this store
                    specialEvent = false;
               }
               else
                    cout << "Not enough money to fix the phone!!" << endl;
          }

     }

     cout << endl << "There was not much to do in the store." << endl;

}