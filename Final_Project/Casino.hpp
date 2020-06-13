/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the Casino header for the Casino class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character to improves attributes
                 in order to complete the game.
*******************************************************************************/


#ifndef CASINO_HPP
#define CASINO_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include <vector>
#include <ctime>


using std::string;
using std::cout;
using std::endl;

class Casino : public Space {

private:

     //This variable stores the current amount of money the character has
     double userMoney;

     //This function peforms the guess number game.
     void GuessNumber();

     //This function handles the palindrome challenge.
     void PalindromeChallenge();

     //This function handles the dice roll challenge.
     void BiasedDieChallenge();
     

public:

     //nondefault Constructor
     Casino(string spaceName, MainCharacter* user1);

     //execute the special action
     void SpecialAction() override;

     //destructor
     ~Casino() {}

};

#endif 