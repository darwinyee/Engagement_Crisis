/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the ToyStore codes for the ToyStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "ToyStore.hpp"


//nondefault Constructor
ToyStore::ToyStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "ToyStore";
     this->user1 = user1;
     specialEvent = true;

}



//execute the special action
void ToyStore::SpecialAction() {

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
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 

}



//function to select a random event
void ToyStore::HintEvents() {

     //message prompt for the user
     cout << endl << "You are very nervous since the time is approaching and you haven't bought everything yet!"
          << endl << "Seeing many young happy faces playing with the toys they love relaxes your mind a bit." << endl;

     //opportunity to buy a special toy
     if (specialEvent) {

          cout << endl << "Something suddenly caught your eye!! \nA limited edition robot that you loved when you were small was on clearance ($300 -> $30)!!"
               << endl << "Do you want to buy it (y/n)? ";
          if (getYesOrNo() == "y") {
               user1->AdjustMoney(-30);
               user1->AddItem("A Limited Edition Robot", false);
               //no more special event for this store
               specialEvent = false;
          }         

     }

     //some hints or some coupon opportunity
     int randNum = rand() % 5;

     if (randNum == 0) {

          cout << endl << "A kid accidentally bumped into you. \nYou kneed down and smiled at him and he said sorry and ran away.\n"
               << endl << "You noticed a paper with a % sign hiding under the pile of toys. \nA closer look revealed that it was a coupon!"
               << endl << "You immediately picked it up...";
          user1->AddItem(CouponGenerator());

     }
     else if (randNum < 3) {
          cout << endl << "Two parents next to you were talking about a man they just met at the food court."
               << endl << "That man was looking for a Limited Edition Robot. \nYou took a peek at the photo on their phone and did not pay much attention." << endl;
     }
     else
          cout << endl << "You chatted with a store associate and he wished you luck for your proposal!" << endl;

}



//this function randomly generates a coupon
string ToyStore::CouponGenerator() {

     int randNum = rand() % 9;
     if (randNum == 0)
          return "5% Jewelry Coupon";
     else if (randNum < 4)
          return "10% Clothes Coupon";
     else
          return "2% Flower Coupon";

}