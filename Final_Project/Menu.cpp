/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-25-2019
** Description:  This is a menu function definitions that is designed to display
                 the header and options.
*******************************************************************************/

#include "Menu.hpp"
#include "InputValidation2.hpp"


//This function displays the header block
void DisplayHeader(string inputName) {

     cout << endl << "\tWelcome to " << inputName << "!" << endl ;

}



//This function displays the option block
void DisplayOptions() {

     cout << endl << endl << "Please select one of the options below:";
     cout << endl << endl << "\t1. Start Engagement Crisis: a text-based Romance Game" << endl;
     cout << "\t2. Exit" << endl << endl;

}

