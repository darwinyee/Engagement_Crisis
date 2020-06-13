/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-29-2019
** Description:  This is the ClothesStore header for the ClothesStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef CLOTHESSTORE_HPP
#define CLOTHESSTORE_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <cmath>
#include <ctime>


using std::string;
using std::cout;
using std::endl;

class ClothesStore : public Space {

private:

     //price for the suit
     int clothesPrice;

     //function to give a hint, not always useful
     void HintEvents();

     //function to purchase the necessary item
     void PurchaseClothes();

public:

     //nondefault Constructor
     ClothesStore(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~ClothesStore() {}

};

#endif 