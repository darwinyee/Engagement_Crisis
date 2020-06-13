/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the MainCharacter header.  It creates the main character.
                 It has a pointer pointing to the space he is currently at.  It
                 has an inventory queue for storing items.  It has variables for
                 total money and a function to check if all the necessary items
                 have been obtained.
*******************************************************************************/


#ifndef MAINCHARACTER_HPP
#define MAINCHARACTER_HPP

#include <iostream>
#include <string>

#include "DoublyLinkedList.hpp"


class Space;

using std::string;
using std::cout;
using std::endl;

class MainCharacter {

private:

     int timeRemaining;

     double totalMoney;

     string name;

     //a space pointer pointing to the current space the character is in
     Space* currentSpace;

     //an inventory linkedlist for storing items obtained
     DoublyLinkedList inventory;

     //This function helps to build a possible location string
     string buildPosLocString(string moveOption);

     //variables to keep track of game status
     bool endGame, completeGoal;

     //functions to display the ending on screen
     void GameEnding();

public:

     //constructor
     MainCharacter();

     //This function moves the character to the next space
     void Move(Space* nextSpace = nullptr);

     //This function checks to see if all necessary items have been gathered
     bool CheckNeededItem();

     //This function checks to see if the user has a specific item
     int CheckSpecificItem(string item);

     //This function adds an item to the inventory
     void AddItem(string item, bool showPrompt=true);

     //This function removes an item from the inventory
     void RemoveItem(string item, bool showPrompt = true);

     //This function removes all of the specific items from the inventory
     void RemoveAllSpecific(string item);

     //This function prints the current character information on screen
     void PrintCharacterInfo();

     //This function checks the current game status, including time limit, money, and item collected
     bool CharacterGameStatus();

   //getter/setter function
     //These function get/set the total money the character has
     void AdjustMoney(double offset) { totalMoney += offset; }
     double CheckMoney() { return totalMoney; }

     //These function get/set the time remaining
     void AdjustTime(int offset) { timeRemaining += offset; }
     int TimeRemain() { return timeRemaining; }

     //This function returns the name of the user
     string userName() { return name; }

     //This function returns the currentSpace the character is in
     Space* CurrentLoc() { return currentSpace; }

     //destructor
    // ~MainCharacter();

};

#endif 