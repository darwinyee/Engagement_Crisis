/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-29-2019
** Description:  This is the FlowerStore header for the FlowerStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "FlowerStore.hpp"


//nondefault Constructor
FlowerStore::FlowerStore(string spaceName, MainCharacter* user1) {

     this->spaceName = spaceName;
     spaceType = "FlowerStore";
     this->user1 = user1;
     flowerPrice = 100;
     specialEvent = true;

}



//function to give a hint, not always useful
void FlowerStore::HintEvents() {

     string message = "";

     int randHint = rand() % 3;
     if (randHint == 0)
          message = "There is a promotion going on! \nIf you buy $150 of flower you will receive a 10% Coupon \nfor Clothes and a 5% Coupon for Jewelry.";
     else if (randHint == 1)
          message = "The owner wished you luck for your proposal. \nHe mentioned that family was fun but kids were clumsy. \nSo, he always had some bandages with him just in case.";
     else
          message = "The owner said Roses were good for proposal.  \nRoses were popular so he had a lot in store. \nHe claimed to have the lowest price in town.";

     cout << endl << message << endl;

     //Special event only happens once
     if (specialEvent) {
          int randEvent = rand() % 10;
          if (randEvent == 0) {
               //the event happens once only

               cout << endl << "While walking around the store, a flower pot fell from the shelf and nearly hit your head!"
                    << endl << "As an apology, the owner offers a bouquet of Roses to you for free! "
                    << endl << "Do you want to accept it? (y/n) ";

               if (getYesOrNo() == "y") {
                    user1->AddItem("Bouquet of Roses", false);
                    cout << "You kindly accepted the apology. " << endl;
               }
               else
                    cout << "You kindly accepted the apology, but your hands were full so you didn't take the offer." << endl;

               specialEvent = false;
          }
     }
}



//function to purchase the necessary item
void FlowerStore::PurchaseFlower() {

     cout << "The Roses cost $" << flowerPrice << ". Do you want to purchase it? ";
     if (getYesOrNo() == "y") {
          
          double finalTotal = flowerPrice;
          double adjPrice = flowerPrice;

          //ask if the user wants to spend $200 for two coupons
          cout << "We have a promotion today! \nIf you spend $150 you will receive a 10% Coupon for Clothes and a 5% Coupon for Jewelry.\n Do you want to spend $150 more? (y/n) ";
          if (getYesOrNo() == "y") {
               adjPrice += 50;
               finalTotal += 50;
          }

          //automatically use coupon to reduce the ringPrice
          int couponCt = user1->CheckSpecificItem("2% Flower Coupon");

          //total coupon amount
          double couponAmt = pow(0.98, couponCt);

          //adjust the final price
          adjPrice = adjPrice * couponAmt;


          if (user1->CheckMoney() >= adjPrice) {
               user1->AdjustMoney(-adjPrice);
               
               //display a coupon message
               if (couponCt) {
                    cout << endl << couponCt << " coupon(s) applied! Your saving is $" << finalTotal - adjPrice << "!" << endl;
                    //remove all coupons
                    user1->RemoveAllSpecific("2% Flower Coupon");
               }
               user1->AddItem("Bouquet of Roses", false);

               //add two new coupons if spent $150
               if (finalTotal > 100) {
                    user1->AddItem("10% Clothes Coupon");
                    user1->AddItem("5% Jewelry Coupon");
               }
          }
          else {
               cout << "Not enough money to buy the flowers!" << endl;
          }
     }
}



//execute the special action
void FlowerStore::SpecialAction() {

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
          cout << "\t2. Purchase the flower for the proposal." << endl;
          cout << "\t3. Leave the store. " << endl << endl;

          cout << ">>>What would you like to do? ";

          userIn = getValidInput("1|2|3");

          if (userIn == "1") {

               //give a hint
               HintEvents();
          }
          else if (userIn == "2")
               //purchase the flowers
               PurchaseFlower();

     } while (userIn != "3");
     //take the end time
     time(&outStore);

     //adjust the time remaining for the character
     int timeSpent = (int)difftime(outStore, inStore);
     user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 


}
