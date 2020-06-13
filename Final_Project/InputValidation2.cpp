/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for input validation functions.
                 I consulted www.cplusplus.com for cctype function isdigit().
*******************************************************************************/

#include "InputValidation2.hpp"

//boolean function for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string specificInput) {

     //put all the specific inputs separated by | into vector
     vector <string> inputNeeded;
     unsigned posAfterDelimit = 0;
     for (unsigned n = 0; n < specificInput.length(); n++) {
          if (specificInput.substr(n, 1) == "|") {
               inputNeeded.push_back(specificInput.substr(posAfterDelimit, n - posAfterDelimit));
               posAfterDelimit = n + 1;
          }
     }
     //for the last input needed
     if (posAfterDelimit < specificInput.length())
          inputNeeded.push_back(specificInput.substr(posAfterDelimit, specificInput.length() - posAfterDelimit));

     //loop through the inputNeeded and return true if match found    
     for (unsigned m = 0; m < inputNeeded.size(); m++) {
          if (inputToCheck == inputNeeded[m])
               return true;
     }

     return false;
}

//boolean function for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound, int highBound) {

     unsigned loopStartPos = 0;   //starting position for inputToCheck to start checking
     unsigned digitCount = 0;

     //restrict the length of the input
     if (inputToCheck.length() > 9)
          return false;

     //check to see if the input is negative
     if (inputToCheck.substr(0, 1) == "-" && !isNonNegative && inputToCheck.length()>1)
          loopStartPos = 1;

     //check to see if the input is an valid integer
     for (unsigned n = loopStartPos; n < inputToCheck.length(); n++) {
          if (!std::isdigit(inputToCheck[n]))
               return false;
          else
               digitCount++;
     }

     if (digitCount < 1)
          return false;

     //make sure the integer is within bound
     if ((std::stoi(inputToCheck) < lowBound) || (std::stoi(inputToCheck) > highBound))
          return false;

     return true;

}


//boolean function for checking decimal only
bool isDoubleOnly(string inputToCheck, bool isNonNegative, double lowBound, double highBound) {

     unsigned loopStartPos = 0;   //starting position for inputToCheck to start checking
     unsigned dotCount = 0;
     unsigned digitCount = 0;

     //restrict the length of the input
     if (inputToCheck.length() > 9)
          return false;

     //check to see if the input is negative
     if (inputToCheck.substr(0, 1) == "-" && !isNonNegative && inputToCheck.length() > 1)
          loopStartPos = 1;

     //check to see if the input is an valid integer
     for (unsigned n = loopStartPos; n < inputToCheck.length(); n++) {
          if (!std::isdigit(inputToCheck[n])) {
               if (inputToCheck[n] == '.') {
                    if (dotCount == 1)
                         return false;
                    else
                         dotCount = 1;
               }else
                    return false;
          }
          else
               digitCount++;
     }

     if (digitCount < 1)
          return false;

     //make sure the integer is within bound
     if ((std::stod(inputToCheck) < lowBound) || (std::stod(inputToCheck) > highBound))
          return false;

     return true;

}


//function to check valid string input (alphanumeric + underscore + space + & + ( + ) + . + ,)
bool isStringInputValid(string inputToCheck) {
     //alphanum count
     int numOfAlphaNum = 0;
     int spaceCount = 0;

     if (inputToCheck.length() == 0)
          return false;

     //loop through the input to check one by one
     for (unsigned n = 0; n < inputToCheck.length(); n++) {
          if (!std::isalnum(inputToCheck[n])) {
               if (inputToCheck[n] == ' ')
                    spaceCount++;
          }
          else
               numOfAlphaNum++;
     }

     //if only has space return false
     if (numOfAlphaNum == 0 && spaceCount > 0)
          return false;
     return true;
}


//function to get valid input from user
string getValidInput(string specificInput) {

     string userInput = "";

     //get user's selection
     std::getline(cin, userInput);

     //input validation
     while (!isSpecificInputValid(userInput, specificInput)) {
          cout << "Invalid Entry! Please enter " + specificInput +" only! ";
          std::getline(cin, userInput);
     }

     return userInput;
}

//function to get valid integers input from user
int getValidInputInteger(int highBound, int lowBound) {

     string userInput = "";

     //get user's input value
     std::getline(cin, userInput);

     //input validation
     bool IsNotNegative = false;
     if (lowBound >= 0)
          IsNotNegative = true;

     while (!isIntegersOnly(userInput, IsNotNegative, lowBound, highBound)) {
          cout << "Invalid integer! Please enter again! (" << lowBound << " <= x <= " << highBound <<")";
          std::getline(cin, userInput);
     }

     return std::stoi(userInput);
}

//function to get valid decimal input from user
double getValidInputDouble(double highBound, double lowBound) {

     string userInput = "";

     //get user's input value
     std::getline(cin, userInput);

     //input validation
     bool IsNotNegative = false;
     if (lowBound >= 0)
          IsNotNegative = true;

     while (!isDoubleOnly(userInput, IsNotNegative, lowBound, highBound)) {
          cout << "Invalid Decimal! Please enter again! (" << lowBound << " <= x <= " << highBound << ")";
          std::getline(cin, userInput);
     }

     return std::stod(userInput);
}

//function to get valid string input (alphanumeric + underscore + space only)
string getValidInputString() {

     string userInput = "";

     //get user's selection
     std::getline(cin, userInput);

     //input validation
     while (!isStringInputValid(userInput)) {
          cout << "Invalid Entry! Please enter again! ";
          std::getline(cin, userInput);
     }

     return userInput;

}

//function to get a yes/no input from user
string getYesOrNo() {

     string yesNo = getValidInput("y|Y|n|N");

     yesNo = tolower(yesNo[0]);

     return yesNo;

}