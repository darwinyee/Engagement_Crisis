/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the ToyStore header for the ToyStore class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef TOYSTORE_HPP
#define TOYSTORE_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <ctime>


using std::string;
using std::cout;
using std::endl;


class ToyStore : public Space {

private:

     //function to give a hint, not always useful
     void HintEvents();

     //this function randomly generates a coupon
     string CouponGenerator();

     //this variable keeps track of the special event happened in this store
     bool specialEvent;

public:

     //nondefault Constructor
     ToyStore(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~ToyStore() {}

};

#endif 