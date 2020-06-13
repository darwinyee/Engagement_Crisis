/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the function definition for the Restroom class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "Restroom.hpp"

//Constructor
Restroom::Restroom(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "Restroom";
     this->user1 = user1;
}



//function to select a random event
void Restroom::ExecuteEvents() {

     int eventSelection = rand() % 5;

     if (eventSelection < 2)
          RewardEvent();
     else
          AttributeLostEvent();

}



//reward possibility function
void Restroom::RewardEvent() {

     int rewardSelect = rand() % 6;
     if (rewardSelect == 0) {

          // reward : money reward, lose time
               cout << endl << "As you go into the last room of the restroom, you found a phone on top of the toilet ringing.  \nYour intuition tells you this is the owner calling. What should you do? (1=Answer, 2=ignore) ";
          if (getValidInput("1|2") == "1") {

               cout << "You answered the phone and waited 15 mins for the owner to show up!!\nTo appreciate your help, the owner gave you $50 bucks as a reward!" << endl;
               user1->AdjustMoney(50);
               user1->AdjustTime(-15);

          }
          else {
               cout << "You ignored!" << endl;
          }

     }
     else if (rewardSelect < 4) {

          //first reward: item reward
          cout << endl << "As you walk out of the restroom, a child tripped, fell and hurt his knee. \nWhat should you do? (1=help, 2=ignore) ";
          if (getValidInput("1|2") == "1") {
               if (user1->CheckSpecificItem("bandage")) {
                    user1->RemoveItem("bandage", false);
                    cout << "An act of kindness turns to be rewarding!! You comforted the child and gave him a bandage.\nAs a thank you to you, the father gave you a coupon!" << endl;
                    user1->AddItem(CouponGenerator());
               }
               else
                    cout << "You tried to help. But without a bandage there is not much you can do!" << endl;
          }
          else {
               cout << "You ignored!" << endl;
          }

     }
     else {

          //third reward: a coupon
          cout << endl << "As you walk out of the restroom, you noticed a paper with a percentage sign printed on it. \nUpon closer inspection you realized this was a coupon.  \nYou quickly picked it up!" << endl;
          user1->AddItem(CouponGenerator());

     }

}



//attribute lost function
void Restroom::AttributeLostEvent() {

     int lostSelect = rand() % 4;
     if (lostSelect != 0) {
          //lose some time
          cout << endl << "You really needed to go to the restroom!! \nUnfortunately, only 1 toilet was functioning for the time \nbeing and you waited for 10 mins!!" << endl;
          user1->AdjustTime(-10);
     }
     else {
          //lose some money
          cout << endl << "You were in a hurry and sweat a lot, so you wiped your face with a paper towel taken from your pocket. \nUpon leaving the restroom you realized you dropped a $20 bill and the money could never been found..." << endl;
          user1->AdjustMoney(-20);
     }
}


//this function randomly generates a coupon
string Restroom::CouponGenerator() {

     int randNum = rand() % 9;
     if (randNum == 0)
          return "5% Jewelry Coupon";
     else if (randNum < 4)
          return "10% Clothes Coupon";
     else
          return "2% Flower Coupon";

}



//execute the special action
void Restroom::SpecialAction() {

     cout << endl << ">>>Do you want to go to the " + spaceName + ": ";
     string userIn = getYesOrNo();

     if (userIn == "y") {
          //display the title header for the restroom
          cout << string(60, '*');
          cout << endl << string(15, ' ') << "You are in the " + spaceName + "!" << endl;
          cout << string(60, '*');

          //two time variables to keep track of time spent in the store
          time_t inStore, outStore;
          time(&inStore);

          //execute a list of random event
          ExecuteEvents();

          //take the end time
          time(&outStore);

          //adjust the time remaining for the character
          int timeSpent = (int)difftime(outStore, inStore);
          user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 
     }

}
