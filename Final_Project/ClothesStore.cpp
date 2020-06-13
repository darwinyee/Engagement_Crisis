/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-29-2019
** Description:  This is the ClothesStore header for the ClothesStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "ClothesStore.hpp"


//nondefault Constructor
ClothesStore::ClothesStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "ClothesStore";
     this->user1 = user1;
     clothesPrice = 300;

}



//function to give a hint, not always useful
void ClothesStore::HintEvents() {

     string message = "";

     int randHint = rand() % 3;
     if (randHint == 0)
          message = "You asked to see if there were promotions going on round the store. \nUnfortunately, promotions just ended yesterday!";
     else if (randHint == 1)
          message = "A salesman approached you offering help.  You asked his recommendation for a suit for proposal. \nHe recommended one ($300) that would make you look handsome, attractive and reliable. ";
     else
          message = "Chatting with the owner about your proposal, he said the Jewelry Store usually accepted price match!\n He could not do that because his margin was low.";

     cout << endl << message << endl;

}



//function to purchase the necessary item
void ClothesStore::PurchaseClothes() {

     cout << "The suit costs $" << clothesPrice << "(before coupon). Do you want to purchase it? ";
     if (getYesOrNo() == "y") {

          //automatically use coupon to reduce the ringPrice
          int couponCt = user1->CheckSpecificItem("10% Clothes Coupon");

          //total coupon amount
          double couponAmt = pow(0.9, couponCt);

          //adjust the ring price
          double adjPrice = clothesPrice * couponAmt;


          if (user1->CheckMoney() >= adjPrice) {
               user1->AdjustMoney(-adjPrice);
               
               //display a coupon message
               if (couponCt) {
                    cout << endl << couponCt << " coupon(s) applied! Your saving is $" << clothesPrice - adjPrice << "!" << endl;
                    //remove all coupons
                    user1->RemoveAllSpecific("10% Clothes Coupon");
               }
               user1->AddItem("New Suit", false);
          }
          else {
               cout << "Not enough money to buy the suit!" << endl;
          }
     }
}


//execute the special action
void ClothesStore::SpecialAction() {

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
          cout << "\t2. Purchase the suit for the proposal." << endl;
          cout << "\t3. Leave the store. " << endl << endl;

          cout << ">>>What would you like to do? ";

          userIn = getValidInput("1|2|3");

          if (userIn == "1") {

               //give a hint
               HintEvents();
          }
          else if (userIn == "2")
               //purchase the ring
               PurchaseClothes();

     } while (userIn != "3");
     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 

}


