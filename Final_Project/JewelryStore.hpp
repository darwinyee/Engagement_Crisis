/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-27-2019
** Description:  This is the JewelryStore header for the JewelryStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef JEWELRYSTORE_HPP
#define JEWELRYSTORE_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <cmath>
#include <ctime>


using std::string;
using std::cout;
using std::endl;

class JewelryStore : public Space {

private:

     //price for the engagement ring
     int ringPrice;

     //function to give a hint, not always useful
     void HintEvents();

     //function to purchase the necessary item
     void PurchaseJewelry();

public:

     //nondefault Constructor
     JewelryStore(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~JewelryStore() {}

};

#endif 