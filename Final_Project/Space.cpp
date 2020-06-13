/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Space function code.  It contains four space pointers
                 representing spaces pointed to by this space. It also has
                 functions that are shared by all spaces.  Space class is an
                 abstract class
*******************************************************************************/


#include "Space.hpp"


//constructor
Space::Space() {

     //setup all the variables
     left = right = top = bottom = nullptr;

     user1 = nullptr;

     hasCharacter = false;

     visitCt = 0;

}



//This function gets the surrounding spaces' names
string Space::GetSurroundSpaces() {

     //string for option selection
     string selection = "";

     if (left) 
          selection = "l";

     if (right) 
          selection = (selection == "") ? (selection + "r") : (selection + "|r");    

     if (top) 
          selection = (selection == "") ? (selection + "t") : (selection + "|t");     

     if (bottom) 
          selection = (selection == "") ? (selection + "b") : (selection + "|b");
     

     return selection;

}