/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is the Map class codes.  It creates the map with spaces.
                 The locations for spaces are fixed, but each space is assigned
                 to a different location every time the game starts.  It has
                 a function to print the map.
*******************************************************************************/


#include "SiteMap.hpp"


//The constructor shuffles the location of the spaces and generates the map for the game
SiteMap::SiteMap(MainCharacter* user1) {

     //set the user1 pointer to the current user
     this->user1 = user1;

     //set up the stores and their names
     SetStoresAndNames();

     //create all the spaces and stores the address to the space pointer array
     int counter = 0;
     map<string, string>::iterator it;
     for (it = storeNameAndType.begin(); it != storeNameAndType.end(); it++) {
          spaceList[counter] = AddSpace(it->first, it->second);
          counter++;
     }

     //Randomize the spaces' locations
     RandomizeSpace();

     //Adjust the neighbors of each space according to a predefined way
     SetNeighbor();

     //Start the user at a jewelry store
     Space* tempLoc1 = SpecificLoc("Kay Jewelers");
     
     startingLocation = (tempLoc1 == nullptr) ? spaceList[0] : tempLoc1;
     user1->Move(startingLocation);

}



//This function returns the address of the first occurance of a store specified
//return nullptr if the store is not found
Space* SiteMap::SpecificLoc(string spaceName) {

     for (int n = 0; n < 10; n++) {
          if (spaceList[n]->GetName() == spaceName)
               return spaceList[n];
     }
     
     return nullptr;
}



//This function dynamically creates a space and returns the address of the new space
Space* SiteMap::AddSpace(string spaceName, string spaceType) {

     Space* temp = nullptr;

     if (spaceType == "Restroom")
          temp = new Restroom(spaceName, user1);
     else if (spaceType == "JewelryStore")
          temp = new JewelryStore(spaceName, user1);
     else if (spaceType == "Casino")
          temp = new Casino(spaceName, user1);
     else if (spaceType == "ToyStore")
          temp = new ToyStore(spaceName, user1);
     else if (spaceType == "FoodCourt")
          temp = new FoodCourt(spaceName, user1);
     else if (spaceType == "AppleStore")
          temp = new AppleStore(spaceName, user1);
     else if (spaceType == "DepartmentStore")
          temp = new DepartmentStore(spaceName, user1);
     else if (spaceType == "FlowerStore")
          temp = new FlowerStore(spaceName, user1);
     else if (spaceType == "ClothesStore")
          temp = new ClothesStore(spaceName, user1);

     return temp;
}



//This function randomizes the list of spaces
void SiteMap::RandomizeSpace() {

     //Randomize the location of the empty space on the board and store to a vector
     spaceLoc.clear();
     for (int i = 0; i < 10; i++)
          spaceLoc.push_back(i);

     std::random_shuffle(spaceLoc.begin(), spaceLoc.end());

}



//Store the type of spaces and names to the map variable
void SiteMap::SetStoresAndNames() {

     storeNameAndType.insert(std::pair<string, string>("Restroom 1", "Restroom"));
     storeNameAndType.insert(std::pair<string, string>("Restroom 2", "Restroom"));
     storeNameAndType.insert(std::pair<string, string>("Kay Jewelers", "JewelryStore"));
     storeNameAndType.insert(std::pair<string, string>("Lucky Casino", "Casino"));
     storeNameAndType.insert(std::pair<string, string>("Children's Paradise", "ToyStore"));
     storeNameAndType.insert(std::pair<string, string>("Food Court", "FoodCourt"));
     storeNameAndType.insert(std::pair<string, string>("Apple Store", "AppleStore"));
     storeNameAndType.insert(std::pair<string, string>("Macy's", "DepartmentStore"));
     storeNameAndType.insert(std::pair<string, string>("Men's Wearhouse", "ClothesStore"));
     storeNameAndType.insert(std::pair<string, string>("Eternal Roses", "FlowerStore"));

}



/*This function sets the neighbors of each space according to a predefined way

               3---5
               |   |
           1---2---4---6
                   |   |
                   8---7---9---10
*/
void SiteMap::SetNeighbor() {

     //manually set each neighbor for each space, using the vector location which is in random order

     //Location 1
     spaceList[spaceLoc[0]]->SetRight(spaceList[spaceLoc[1]]);

     //Location 2
     spaceList[spaceLoc[1]]->SetLeft(spaceList[spaceLoc[0]]);
     spaceList[spaceLoc[1]]->SetRight(spaceList[spaceLoc[3]]);
     spaceList[spaceLoc[1]]->SetTop(spaceList[spaceLoc[2]]);

     //Location 3
     spaceList[spaceLoc[2]]->SetRight(spaceList[spaceLoc[4]]);
     spaceList[spaceLoc[2]]->SetBottom(spaceList[spaceLoc[1]]);

     //Location 4
     spaceList[spaceLoc[3]]->SetLeft(spaceList[spaceLoc[1]]);
     spaceList[spaceLoc[3]]->SetRight(spaceList[spaceLoc[5]]);
     spaceList[spaceLoc[3]]->SetTop(spaceList[spaceLoc[4]]);
     spaceList[spaceLoc[3]]->SetBottom(spaceList[spaceLoc[7]]);

     //Location 5
     spaceList[spaceLoc[4]]->SetLeft(spaceList[spaceLoc[2]]);
     spaceList[spaceLoc[4]]->SetBottom(spaceList[spaceLoc[3]]);

     //Location 6
     spaceList[spaceLoc[5]]->SetLeft(spaceList[spaceLoc[3]]);
     spaceList[spaceLoc[5]]->SetBottom(spaceList[spaceLoc[6]]);

     //Location 7
     spaceList[spaceLoc[6]]->SetLeft(spaceList[spaceLoc[7]]);
     spaceList[spaceLoc[6]]->SetRight(spaceList[spaceLoc[8]]);
     spaceList[spaceLoc[6]]->SetTop(spaceList[spaceLoc[5]]);

     //Location 8
     spaceList[spaceLoc[7]]->SetRight(spaceList[spaceLoc[6]]);
     spaceList[spaceLoc[7]]->SetTop(spaceList[spaceLoc[3]]);

     //Location 9
     spaceList[spaceLoc[8]]->SetLeft(spaceList[spaceLoc[6]]);
     spaceList[spaceLoc[8]]->SetRight(spaceList[spaceLoc[9]]);

     //Location 10
     spaceList[spaceLoc[9]]->SetLeft(spaceList[spaceLoc[8]]);

}



/*This function prints the map on screen.

               3---5
               |   |
           1---2---4---6
                   |   |
                   8---7---9---10
*/
void SiteMap::PrintMap() {

     //array to store map location
     string mapLoc[] = { "1","2","3","4","5","6","7","8","9","10" };

     //Capitalize the letter location if the character is at that location
     for (unsigned n = 0; n < spaceLoc.size(); n++) {

          if (spaceList[spaceLoc[n]]->HasCharacter())
               //mapLoc[n] = toupper(mapLoc[n]);
               mapLoc[n] = "X";

     }

     cout << endl;
     cout << "Mall Map:" << endl;
     cout << string(15, ' ') << mapLoc[2] << "---"  << mapLoc[4] << endl;
     cout << string(15, ' ') << "|   |" << endl;
     cout << string(11, ' ') << mapLoc[0] << "---" << mapLoc[1] << "---" << mapLoc[3] << "---" << mapLoc[5] << endl;
     cout << string(11, ' ') << "        |   |" << endl;
     cout << string(19, ' ') << mapLoc[7] << "---" << mapLoc[6] << "---" << mapLoc[8] << "---" << mapLoc[9] << endl;
     cout << endl << "     *X = Your current location" << endl << endl;

     //print the key for the location
     for (unsigned n = 0; n < spaceLoc.size(); n++) {

          cout << "\t" << n+1 << ") " << spaceList[spaceLoc[n]]->GetName();
          if (spaceList[spaceLoc[n]]->HasCharacter())
               cout << " <--- You are here!";
          cout << endl;

     }

     cout << endl;
}

//destructor
SiteMap::~SiteMap() {

     for (unsigned n = 0; n < spaceLoc.size(); n++) {

          delete spaceList[n];
          spaceList[n] = nullptr;

     }

}