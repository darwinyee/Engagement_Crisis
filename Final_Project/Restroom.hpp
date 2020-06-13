/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Restroom header for the Restroom class, which is 
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef RESTROOM_HPP
#define RESTROOM_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <ctime>


using std::string;
using std::cout;
using std::endl;

class Restroom : public Space {

private:

     //function to select a random event
     void ExecuteEvents();

     //reward possibility function
     void RewardEvent();

     //attribute lost function
     void AttributeLostEvent();

     //this function randomly generates a coupon
     string CouponGenerator();

public:

     //nondefault Constructor
     Restroom(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~Restroom() {}
    
};

#endif 