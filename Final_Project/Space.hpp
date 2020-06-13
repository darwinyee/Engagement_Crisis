/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Space class header.  It contains four space pointers
                 representing spaces pointed to by this space. It also has 
                 functions that are shared by all spaces.  Space class is an
                 abstract class
*******************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include "MainCharacter.hpp"

using std::string;
using std::cout;
using std::endl;


class Space {

protected:
     Space* left, *right, *top, *bottom;

     string spaceName, spaceType;

     MainCharacter* user1;

     bool hasCharacter;

     int visitCt;

public:

     //constructor
     Space();

     //This function gets the surrounding spaces' names
     string GetSurroundSpaces();

     //This virtual function performs the special action for a particular space
     virtual void SpecialAction() = 0;

   //Setter/getter functions

     //These functions gets/sets the name of the space
     void SetName(string spaceName) { this->spaceName = spaceName; }
     string GetName() { return this->spaceName; }

     //This function gets the type of the space
     string GetType() { return this->spaceType; }

     //These functions gets/sets the space on the left of this space
     void SetLeft(Space* left) { this->left = left; }
     Space* GetLeft() { return this->left; }

     //These functions gets/sets the space on the right of this space
     void SetRight(Space* right) { this->right = right; }
     Space* GetRight() { return this->right; }

     //These functions gets/sets the space on the top of this space
     void SetTop(Space* top) { this->top = top; }
     Space* GetTop() { return this->top; }

     //These functions gets/sets the space at the bottom of this space
     void SetBottom(Space* bottom) { this->bottom = bottom; }
     Space* GetBottom() { return this->bottom; }

     //These functions gets/sets the hasCharacter boolean
     void SethasCharacter(bool hasCharacter) { this->hasCharacter = hasCharacter; }
     bool HasCharacter() { return this->hasCharacter; }

     //These functions gets/sets the number of visits this space receives
     void IncreaseVisitCt() { visitCt++; }
     int TotalVisit() { return visitCt; }

     //virtual destructor
     virtual ~Space() {}

};

#endif // !SPACE_HPP
