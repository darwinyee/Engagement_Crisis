/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-18-2019
** Description:  This is the header file for the Menu functions, which is designed 
                 to display a menu header and the option menu.
*******************************************************************************/


#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
using std::string;


//Define the interface of the Menu class

//This function displays the header block
void DisplayHeader(string inputName);

//This function displays the option block
void DisplayOptions();

#endif
