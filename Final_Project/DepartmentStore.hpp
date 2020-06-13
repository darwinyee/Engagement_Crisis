/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the DepartmentStore header for the class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef DEPARTMENTSTORE_HPP
#define DEPARTMENTSTORE_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <ctime>


using std::string;
using std::cout;
using std::endl;


class DepartmentStore : public Space {

private:

     //function to give a hint, not always useful
     void HintEvents();

     //this variable keeps track of the special event happened in this store
     bool specialEvent;

     //this function gives out free items, which may or may not be useful throughout the game
     void FreeItem();

public:

     //nondefault Constructor
     DepartmentStore(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~DepartmentStore() {}

};

#endif 