/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-29-2019
** Description:  This is the FlowerStore header for the FlowerStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef FLOWERSTORE_HPP
#define FLOWERSTORE_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <cmath>
#include <ctime>


using std::string;
using std::cout;
using std::endl;

class FlowerStore : public Space {

private:

     //price for the flower
     int flowerPrice;

     //variable to make sure the special event happens only once
     bool specialEvent;

     //function to give a hint, not always useful
     void HintEvents();

     //function to purchase the necessary item
     void PurchaseFlower();

public:

     //nondefault Constructor
     FlowerStore(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~FlowerStore() {}

};

#endif 