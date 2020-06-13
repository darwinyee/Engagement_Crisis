/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for input validation functions.
                 I consulted www.cplusplus.com for cctype function isdigit().
*******************************************************************************/

#ifndef DARWIN_YEE_INPUTVALID_HPP
#define DARWIN_YEE_INPUTVALID_HPP

#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

//function interface for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string specficInput); //specificInput: x|y|z...

//function interface for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound = std::numeric_limits<int>::min(), int highBound = std::numeric_limits<int>::max());

//function interface for checking decimal only
bool isDoubleOnly(string inputToCheck, bool isNonNegative, double lowBound = std::numeric_limits<double>::min(), double highBound = std::numeric_limits<double>::max());

//function to check valid string input (alphanumeric + underscore only)
bool isStringInputValid(string inputToCheck);

//function to get valid input from user
string getValidInput(string specificInput); //specificInput: x|y|z...

//function to get valid integers input from user
int getValidInputInteger(int highBound = std::numeric_limits<int>::max(), int lowBound = 0);

//function to get valid decimal input from user
double getValidInputDouble(double highBound, double lowBound = 0);

//function to get valid string input (alphanumeric + underscore only)
string getValidInputString();

//function to get a yes/no input from user
string getYesOrNo();


#endif
