/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Map class header.  It creates the map with spaces.
                 The locations for spaces are fixed, but each space is assigned
                 to a different location every time the game starts.  It has 
                 a function to print the map.
*******************************************************************************/


#ifndef SITEMAP_HPP
#define SITEMAP_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "MainCharacter.hpp"
#include "Space.hpp"
#include "Restroom.hpp"
#include "JewelryStore.hpp"
#include "Casino.hpp"
#include "ToyStore.hpp"
#include "AppleStore.hpp"
#include "FoodCourt.hpp"
#include "DepartmentStore.hpp"
#include "FlowerStore.hpp"
#include "ClothesStore.hpp"


using std::string;
using std::cout;
using std::endl;
using std::map;
using std::vector;


class SiteMap {

private:
     
     //an array of space pointers for all spaces
     Space* spaceList[10];

     //a vector for the corresponding space location on map
     vector<int> spaceLoc;

     //a list of space names and store type
     map<string, string> storeNameAndType;

     //Pointer to store the starting space
     Space* startingLocation;

     //Pointer to the current user
     MainCharacter* user1;

   //private helper function
     
     //Store the type of spaces and names to the map variable
     void SetStoresAndNames();

     //This function dynamically creates a space and returns the address of the new space
     Space* AddSpace(string spaceName, string spaceType);

     //This function randomizes the list of spaces and sets the position of each space
     void RandomizeSpace();

     //This function sets the neighbors of each space according to a predefined way
     void SetNeighbor();

     //This function returns the address of the first occurance of a store specified
     Space* SpecificLoc(string spaceName);


public:

     //constructor
     SiteMap(MainCharacter* user1);

     //This function returns the starting space pointer.
     Space* StartingLoc() { return startingLocation; }

     //This function prints the map on screen, with the space that has a character marked by paratheses
     void PrintMap();

     //destructor
     ~SiteMap();

};

#endif 