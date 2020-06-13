/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-27-2019
** Description:  This is the JewelryStore codes for the JewelryStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "JewelryStore.hpp"


//nondefault Constructor
JewelryStore::JewelryStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "JewelryStore";
     this->user1 = user1;
     ringPrice = 1200;

}



//function to give a hint, not always useful
void JewelryStore::HintEvents() {

     string message = "";

     int randHint = rand() % 3;
     if (randHint == 0)
          message = "You asked to see if there were promotions going on round the store. \nUnfortunately, promotions just ended yesterday!";
     else if (randHint == 1)
          message = "Looking around the store, a salesman approached you.  \nThrough the conversation, you found out that there was a casino nearby,\n and the mall's restrooms were interesting places to check out.";
     else
          message = "Talking to a customer at the store, you found out that coupons were avaliable but hard to find.";

     cout << endl << message << endl;

}



//function to purchase the necessary item
void JewelryStore::PurchaseJewelry() {

     cout << "The engagement ring costs $" << ringPrice << " (before coupon/price match). Do you want to purchase it? ";
     if (getYesOrNo() == "y") {

          //automatically use coupon and price match to reduce the ringPrice
          int couponCt = user1->CheckSpecificItem("5% Jewelry Coupon");
          bool hasPriceMatch = user1->CheckSpecificItem("Ring Price Match Printout");

          //total coupon amount
          double couponAmt = pow(0.95, couponCt);

          //price match 
          double priceMatch = 0;
          if (hasPriceMatch)
               priceMatch = -200;

          //adjust the ring price
          double adjPrice = (ringPrice+priceMatch) * couponAmt;


          if (user1->CheckMoney() >= adjPrice) {
               user1->AdjustMoney(-adjPrice);
               
               //display a coupon message
               if (couponCt) {
                    cout << endl << couponCt << " coupon(s) applied! " << endl;
                    //remove all coupons
                    user1->RemoveAllSpecific("5% Jewelry Coupon");
               }

               //display a price match message
               if (hasPriceMatch) {
                    cout << "The price has been matched to $" << ringPrice + priceMatch << "!" << endl;
                    user1->RemoveAllSpecific("Ring Price Match Printout");
               }

               //display the total savings
               cout << "Your total saving is $" << ringPrice - adjPrice << "!" << endl;

               user1->AddItem("Engagement Ring", false);
          }
          else {
               cout << "Not enough money to buy the ring!" << endl;
          }

     }

}


//execute the special action
void JewelryStore::SpecialAction() {

     cout << string(60, '*');
     cout << endl << string(15, ' ') << "You are in the " + spaceName + "!" << endl;
     cout << string(60, '*');

     //two time variables to keep track of time spent in the store
     time_t inStore, outStore;
     time(&inStore);

     string userIn;
     do {
          cout << endl << "Options:";
          cout << endl << "\t1. Browse around and talk to the salesman." << endl;
          cout << "\t2. Purchase the engagement ring." << endl;
          cout << "\t3. Leave the store. " << endl << endl;

          cout << ">>>What would you like to do? ";

          userIn = getValidInput("1|2|3");

          if (userIn == "1") {

               //give a hint
               HintEvents();
          }
          else if (userIn == "2")
               //purchase the ring
               PurchaseJewelry();

     } while (userIn != "3");

     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 
     
}


