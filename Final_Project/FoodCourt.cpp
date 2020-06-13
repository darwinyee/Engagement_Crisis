/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the FoodCourt codes for the FoodCourt class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "FoodCourt.hpp"


//nondefault Constructor
FoodCourt::FoodCourt(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "FoodCourt";
     this->user1 = user1;
     specialEvent = true;
     bigMeal = true;

}



//execute the special action
void FoodCourt::SpecialAction() {

     cout << string(60, '*');
     cout << endl << string(15, ' ') << "You are in the " + spaceName + "!" << endl;
     cout << string(60, '*');

     //two time variables to keep track of time spent in the store
     time_t inStore, outStore;
     time(&inStore);

     string userIn;
     do {
          cout << endl << "Options:";
          cout << endl << "\t1. Purchase a full meal." << endl;
          cout << "\t2. Purchase some snacks." << endl;
          cout << "\t3. Sit down and relax." << endl;
          cout << "\t4. Leave. " << endl << endl;

          cout << ">>>What would you like to do? ";

          userIn = getValidInput("1|2|3|4");

          if (userIn == "1")
               //purchase food
               PurchaseFood("Full");
          else if (userIn == "2")
               PurchaseFood("Snack");
          else if (userIn == "3")
               HintEvents();

     } while (userIn != "4");

     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 

}



//This function takes care of the food purchase
void FoodCourt::PurchaseFood(string foodType) {

     cout << endl << "Because you are in a hurry, you went with fast food..." << endl;
     int ticketCt = 0;

     if(foodType == "Full"){
          if (bigMeal) {
               cout << endl << "You purchased a full meal with fries, soda and burger ($15). "
                    << endl << "There was a promotion and you got three scratchable tickets." << endl;
               bigMeal = false;
               user1->AdjustMoney(-15);
               ticketCt = 3;
          }
          else {
               cout << endl << "You ate a big meal already and were too full to have another one." << endl;
          }
     }
     else if (foodType == "Snack") {
          cout << endl << "You purchased a small fries ($5). "
               << endl << "There was a promotion and you got one scratchable ticket." << endl;
          user1->AdjustMoney(-5);
          ticketCt = 1;
     }

     if (ticketCt) {
          for (int n = 0; n < ticketCt; n++) {
               if (rand() % 10 == 0) {
                    cout << "You won a coupon!" << endl;
                    user1->AddItem(CouponGenerator());
               }
               else
                    cout << "Sorry, not a winning ticket!" << endl;
          }
     }
}



//function to select a random event
void FoodCourt::HintEvents() {

     //message prompt for the user
     cout << endl << "Weather is nice! To calm yourself a bit, you decided to sit down and rest a bit." << endl;
   

     //special event or hints or some coupon opportunity
     int randNum = rand() % 20;

     if (randNum < 3) {           //special event happens 3/20 times
          //Special event
          if (specialEvent) {

               cout << endl << "You overhearded the person next to you was looking for a Limited Edition Robot."
                    << endl << "Robots are always your favorite. Do you want to learn more about this (y/n)? ";

               if (getYesOrNo() == "y") {
                    cout << "The person was named ""Bob"". \nHe talked about how he loved robot figures \nand showed you a picture of what he was looking for. " << endl;
                    cout << "He said he would pay $150 for it." << endl;

                    if (user1->CheckSpecificItem("A Limited Edition Robot")) {

                         cout << "You realized you just bought the robot!!! \nDo you want to sell it to him (y/n)? ";
                         if (getYesOrNo() == "y") {
                              user1->AdjustMoney(150);
                              user1->RemoveItem("A Limited Edition Robot", false);
                              cout << "He gladly paid $150 for the robot and thanked you for your help!" << endl;
                         }
                         else {
                              cout << "He was disappointed. He quickly said goodbye and rushed to the toy store..." << endl;
                         }

                         //This event only shows up once.  If user decided not to sell the robot then he can never sell it again
                         specialEvent = false;
                    }
                    else
                         cout << "You wished him luck finding his dream robot." << endl;

               }

          }
     }else if(randNum < 10){
          cout << endl << "Someone said there was a casino nearby. \nGambling is not good, but it might be a chance for you..." << endl;
     }
     else {
          cout << endl << "People were discussing how much more expensive things were nowadays than 10 years before. "
               << endl << "Fortunately, store coupons and price match were available for the stores in this mall." << endl;
     }

}



//this function randomly generates a coupon
string FoodCourt::CouponGenerator() {

     int randNum = rand() % 9;
     if (randNum == 0)
          return "5% Jewelry Coupon";
     else if (randNum < 4)
          return "10% Clothes Coupon";
     else
          return "2% Flower Coupon";

}