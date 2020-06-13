/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the FoodCourt header for the FoodCourt class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef FOODCOURT_HPP
#define FOODCOURT_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <ctime>


using std::string;
using std::cout;
using std::endl;


class FoodCourt : public Space {

private:

     //function to give a hint, not always useful
     void HintEvents();

     //this function randomly generates a coupon
     string CouponGenerator();

     //This function takes care of the food purchase
     void PurchaseFood(string foodType);

     //this variable keeps track of the special event happened in this store
     bool specialEvent, bigMeal;

public:

     //nondefault Constructor
     FoodCourt(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~FoodCourt() {}

};

#endif 