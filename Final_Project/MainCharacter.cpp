/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the MainCharacter definition.  It creates the main character.
                 It has a pointer pointing to the space he is currently at.  It
                 has an inventory queue for storing items.  It has variables for
                 total money and a function to check if all the necessary items
                 have been obtained.
*******************************************************************************/

#include "MainCharacter.hpp"
#include "Space.hpp"

//constructor
MainCharacter::MainCharacter() : inventory(5) {

     totalMoney = 1200;
     timeRemaining = 120;
     currentSpace = nullptr;
     endGame = false;
     completeGoal = false;

     //ask for the name
     cout << endl << ">>>What is your name? ";
     name = getValidInputString();

}



//This function moves the character to the next space
void MainCharacter::Move(Space* nextSpace) {

     //reset currentSpace hasCharacter status
     if (currentSpace != nullptr) {
          currentSpace->SethasCharacter(false);
     }

     if (!nextSpace) {    //if location is not given, ask user for it (assumption is currentSpace is not empty)

          //get a string with the possible moving direction
          string moveOption = currentSpace->GetSurroundSpaces();

          //get a moveOption display string
          string displayMov = buildPosLocString(moveOption);         

          //ask user where they wants to move to
          cout << ">>>Where do you want to go next?\n(" + displayMov + "): ";
          string userIn = getValidInput(moveOption);

          //set the currentSpace to the next
          if (userIn == "l")
               currentSpace = currentSpace->GetLeft();
          else if (userIn == "r")
               currentSpace = currentSpace->GetRight();
          else if (userIn == "t")
               currentSpace = currentSpace->GetTop();
          else if (userIn == "b")
               currentSpace = currentSpace->GetBottom();

     }
     else
          currentSpace = nextSpace;

     //set the currentSpace hasCharacter status and increase the number of visits for this space
     if (currentSpace != nullptr) {
          currentSpace->SethasCharacter(true);
          currentSpace->IncreaseVisitCt();
     }

}



//This function helps to build a possible location string
string MainCharacter::buildPosLocString(string moveOption) {

     string returnString = "";
     unsigned startPos = 0;
     string temp = "";

     for (unsigned n = 0; n < moveOption.length(); n++) {
          
          if (moveOption[n] == '|') {
               temp = moveOption.substr(startPos, 1);
               startPos = n + 1;
               if (temp == "l") {
                    returnString = returnString + "l = " + currentSpace->GetLeft()->GetName() + ", ";
               }
               else if (temp == "r") {
                    returnString = returnString + "r = " + currentSpace->GetRight()->GetName() + ", ";
               }
               else if (temp == "t") {
                    returnString = returnString + "t = " + currentSpace->GetTop()->GetName() + ", ";
               }
               else if (temp == "b") {
                    returnString = returnString + "b = " + currentSpace->GetBottom()->GetName() + ", ";
               }
          }
     }

     //for the last location
     temp = moveOption.substr(startPos, 1);
     if (temp == "l") {
          returnString = returnString + "l = " + currentSpace->GetLeft()->GetName();
     }
     else if (temp == "r") {
          returnString = returnString + "r = " + currentSpace->GetRight()->GetName();
     }
     else if (temp == "t") {
          returnString = returnString + "t = " + currentSpace->GetTop()->GetName();
     }
     else if (temp == "b") {
          returnString = returnString + "b = " + currentSpace->GetBottom()->GetName();
     }

     //return the newly constructed string
     return returnString;
}



//This function checks the current game status, including time limit, money, and item collected
bool MainCharacter::CharacterGameStatus() {

     //Check if the character has all the items needed
     if (CheckNeededItem()) {

          cout << endl << "Alas!! You got all the items needed for the proposal!!\nCongratulations, " + name + "!!!" << endl<<endl;
          completeGoal = true;
          endGame = true;

     }
     
     else {
          //then check if the character ran out of time, issue warning if the time is less than 15mins
          if (timeRemaining > 0 && timeRemaining <= 15) {
               cout << endl << "A friendly reminder:\n\tTime is running out!! You have " << timeRemaining << " min(s) left!!" << endl;
          }
          else if (timeRemaining <= 0) {
               cout << endl << "Sorry " + name + ", you ran out of time" << endl;
               endGame = true;
          }

          if (!endGame) {
               //then check if the character ran out of money, issue warning if the money is less than 50, prompt to quit if the money is 0
               if (totalMoney > 0 && totalMoney <= 50) {
                    cout << endl << "A friendly reminder:\n\tYour money reserve is low. Consider going to the Casino to earn some money." << endl;
               }
               else if (totalMoney <= 0) {
                    cout << endl << ">>>You ran out of money!! Do you want to give up? (y/n) ";
                    if (getYesOrNo() == "y") {
                         endGame = true;
                    }
               }
          }
     }
     

     //display the ending on screen
     if (endGame)
          GameEnding();

     return endGame;
}



//functions to display the ending on screen
void MainCharacter::GameEnding() {

     cout << string(60, '*') << endl;
     cout << endl << "EPILOGUE:" << endl;

     if (completeGoal) {
          cout << "\tYou arrived at the Restaurant right on time!! " << endl;
          cout << "\tAfter a romantic candle dinner, you kneed down and proposed to your dream girl!!" << endl;
          cout << "\tAnd she said ""YES"". It was a very, very touching moment... "<< endl;
          cout << "\tIt was the most happiest day ever in your life!!!" << endl << endl;
     }
     else {
          cout << "\tYou could not make it!! A little disappointed..." << endl;
          cout << "\tRegretting, but since you want the most memoriable experience for your girlfriend," << endl;
          cout << "\tyou vowed to be well prepared next time!!" << endl;
          cout << "\tEnjoy a romantic dinner and walk along the shoreline for a beautiful night scene!!" << endl << endl;
     }
}



//This function checks to see if all necessary items have been gathered
bool MainCharacter::CheckNeededItem() {

     bool hasAll = false;

     if (inventory.CurrentSize() > 2) {

          //check if the user has new clothes
          if (!inventory.CheckExist("New Suit"))
               return false;
          //check if the user has flowers
          if (!inventory.CheckExist("Bouquet of Roses"))
               return false;
          //check if the user has the ring
          if (!inventory.CheckExist("Engagement Ring"))
               return false;

          hasAll = true;
     }

     return hasAll;
}



//This function checks to see if the user has the specific item
int MainCharacter::CheckSpecificItem(string item) {

     return inventory.CheckExist(item);

}



//This function adds an item to the inventory
void MainCharacter::AddItem(string item, bool showPrompt) {

     string userIn = "y";
     if (showPrompt) {
          cout << endl << ">>>Do you want to take the " + item + "? ";
          userIn = getYesOrNo();
     }
     
     if(userIn == "y")
          inventory.AddToTail(item);

}



//This function removes an item from the inventory
void MainCharacter::RemoveItem(string item, bool showPrompt) {

     string userIn = "y";
     if (showPrompt) {
          cout << endl << ">>>Do you want to throw away the " + item + "? ";
          userIn = getYesOrNo();
     }
     if (userIn == "y")
          inventory.RemoveSpecific(item);

}



//This function removes all of the specific items from the inventory
void MainCharacter::RemoveAllSpecific(string item) {

     int specificItemCt = inventory.CheckExist(item);
     for (int n = 1; n <= specificItemCt; n++) {

          RemoveItem(item, false);

     }

}



//This function prints the current character information on screen
void MainCharacter::PrintCharacterInfo() {
     cout << string(60, '*');
     cout << endl << string(15, ' ') << "***Current Summary***" << endl;
     cout << endl << "     Money left: $" << totalMoney << "     Time Remaining: " << timeRemaining  << " min(s)" << endl << endl;
     
     inventory.PrintList();
     cout << "currentsize: " << inventory.CurrentSize() << endl;
     cout << endl << "Missing Item(s): \n";
     string missing = "";
     if (!CheckSpecificItem("New Suit"))
          missing = missing + "New Suit, ";
     if (!CheckSpecificItem("Bouquet of Roses"))
          missing = missing + "Bouquet of Roses, ";
     if (!CheckSpecificItem("Engagement Ring"))
          missing = missing + "Engagement Ring, ";
     missing = missing.substr(0, missing.length() - 2);
     cout << missing << endl << endl;
     cout << string(60, '*');
     cout << endl;

}