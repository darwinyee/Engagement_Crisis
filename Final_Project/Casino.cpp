/*******************************************************************************
** Author:       Darwin Yee
** Date:         05-28-2019
** Description:  This is the Casino codes for the Casino class, which is
                 inherited from Space class.  This is one of the spaces which
                 provides opportunities for the character to improves attributes
                 in order to complete the game.
*******************************************************************************/


#include "Casino.hpp"


//This function peforms the guess number game.
void Casino::GuessNumber() {

     //Game prompt
     cout << endl << "\t***Welcome to Guess Number***" << endl;
     cout << endl << "Instruction:" << endl;
     cout << "\t 1. Insert Money   \n\t 2. Set payoff percentage (higher rate, bigger guess range)   \n\t 3. Give your guess    \n\t 4. Enjoy your reward!" << endl;
     cout << endl << "ARE YOU READY (y/n)? ";

     if (getYesOrNo() == "y") {

          double getMoney;
          int payoffPercent, userGuess;

          //Gather all info necessary for the setup of the game
          cout << endl << "Insert Money (10-" << userMoney << "): ";
          getMoney = getValidInputDouble(userMoney,10);
          user1->AdjustMoney(0 - getMoney);

          cout << "Payoff percentage (no % sign, 10-200): ";
          payoffPercent = getValidInputInteger(200, 10);

          //Generate the number
          int machineNum = rand() % (payoffPercent / 5) + 1;

          //ask user for the guess
          cout << endl << "I have my number ready. What is your guess? [" << 1 << "-" << payoffPercent / 5 << "] ";
          userGuess = getValidInputInteger(payoffPercent / 5, 1);

          //Reward the user
          if (userGuess == machineNum) {

               user1->AdjustMoney(getMoney*(payoffPercent + 100) / 100);
               cout << "Lucky You!! You just won $" << getMoney * (payoffPercent) / 100 << "!!" << endl;

          }
          else
               cout << "My number is " << machineNum << ". Better luck next time!! (loss = " << getMoney << ")" << endl;
     }
     else {
          cout << endl << "See you next time!" << endl;
     }

}



//This function handles the palindrome challenge.
void Casino::PalindromeChallenge() {

     //Game prompt
     cout << endl << "\t***Welcome to Palindrome Challenge***" << endl;
     cout << endl << "Description:" << endl;
     cout << "\tA Palindrome of a phase is the original phase plus the reverse of that phase\n\t Example: race => racecar" << endl;
     cout << endl << "Instruction:" << endl;
     cout << "\t 1. Insert Money   \n\t 2. Set payoff percentage (higher rate, longer word length)   \n\t 3. Type in your answer    \n\t 4. Claim your reward if you are faster than the time limit!" << endl;
     cout << endl << "ARE YOU READY (y/n)? ";

     if (getYesOrNo() == "y") {

          int payoffPercent;
          double getMoney;
          //Gather all info necessary for the setup of the game
          cout << endl << "Insert Money (10-" << userMoney << "): ";
          getMoney = getValidInputDouble(userMoney, 10);
          user1->AdjustMoney(0 - getMoney);

          cout << "Payoff percentage (no % sign, 10-200): ";
          payoffPercent = getValidInputInteger(200, 10);

          //calculate the length of the string for the game
          int stringLength = int(payoffPercent / 10.0) + 4;

          //Create the string
          string original = "";
          for (int n = 0; n < stringLength; n++) {

               char temp = rand() % 26 + 97;
               original = original + temp;

          }

          //generate the answer
          string answer = original;
          for (int m = original.length() - 2; m >= 0; m--) 
               answer = answer + original[m];

          //two time objects to keep track of user time
          time_t userB, userA;

          //ask user for the answer
          cout << endl << "Enter the palindrome for <" + original + "> within 10 seconds: ";
          time(&userB);
          string userAnswer = getValidInputString();
          time(&userA);


          //Reward the user
          if (userAnswer == answer) {
               double userTime = difftime(userA, userB);
               cout << endl << "Time spent: " << userTime << "s" << endl;
               if (userTime <= 10.0) {
                    user1->AdjustMoney(getMoney*(payoffPercent + 100) / 100);
                    cout << "Good Job!! You just won $" << getMoney * (payoffPercent) / 100 << "!!" << endl;
               }
               else
                    cout << "Sorry, you need to be faster next time!(loss = " << getMoney << ")" << endl;
          }
          else
               cout << "Sorry, wrong answer!!" << endl;
     }
     else {
          cout << endl << "See you next time!" << endl;
     }

}



//This function handles the dice roll challenge.
void Casino::BiasedDieChallenge() {

     //Game prompt
     cout << endl << "\t***Welcome to Dice Challenge***" << endl;
     cout << endl << "Description:" << endl;
     cout << "\tYou roll a dice. I roll another dice.  If you have a bigger roll you win.\n\tThe higher the payoff, the more bias my dice would be. Good Luck!" << endl;
     cout << endl << "Instruction:" << endl;
     cout << "\t 1. Insert Money   \n\t 2. Set payoff percentage (higher rate, longer word length)   \n\t 3. You roll a dice    \n\t 4. Claim your reward if your roll is bigger!" << endl;
     cout << endl << "ARE YOU READY (y/n)? ";

     if (getYesOrNo() == "y") {

          double getMoney;
          int payoffPercent;
          //Gather all info necessary for the setup of the game
          cout << endl << "Insert Money (10-" << userMoney << "): ";
          getMoney = getValidInputDouble(userMoney, 10);
          user1->AdjustMoney(0 - getMoney);

          cout << "Payoff percentage (no % sign, 10-200): ";
          payoffPercent = getValidInputInteger(200, 10);

          //calculate the number of sides the computer dice will have and roll it
          int userRoll = 0;
          int machineDice = 6 + (payoffPercent - 10) / 5;
          int machineRoll = rand() % machineDice + 1;
          machineRoll = machineRoll > 5 ? 6 : machineRoll;

          //Tell user the result roll his dice
          cout << endl << "I rolled a " << machineRoll << endl;

          userRoll = rand() % 6 + 1;
          cout << "You rolled a " << userRoll << endl;
          

          //Reward the user
          if (userRoll > machineRoll) {             
                user1->AdjustMoney(getMoney*(payoffPercent + 100) / 100);
                cout << "Luck is on your side this time!! You just won $" << getMoney * (payoffPercent) / 100 << "!!" << endl;
          }
          else if(userRoll == machineRoll){
                user1->AdjustMoney(getMoney);
                cout << "Tie game! You got your money back!" << endl;
          }
          else
               cout << "Better luck next time!(loss = " << getMoney << ")" << endl;
     }
     else {
          cout << endl << "See you next time!" << endl;
     }

 }



//nondefault Constructor
 Casino::Casino(string spaceName, MainCharacter* user1) {

      this->spaceName = spaceName;
      spaceType = "Casino";
      this->user1 = user1;
      userMoney = 0;

}

//execute the special action
 void Casino::SpecialAction() {

      cout << string(60, '*');
      cout << endl << string(15, ' ') << "You are in the " + spaceName + "!" << endl;
      cout << string(60, '*');

      //two time variables to keep track of time spent in the store
      time_t inStore, outStore;
      time(&inStore);

      string userIn;
      do {
           //get the current user money
           userMoney = (user1->CheckMoney() > 150) ? 150 : user1->CheckMoney();

           if (userMoney >= 10) {
                cout << endl << "Options:";
                cout << endl << "\t1. Play the Guess Number Game." << endl;
                cout << "\t2. Take the Palindrome Challenge. " << endl;
                cout << "\t3. Play the Die Rolling Game. " << endl;
                cout << "\t4. Leave " << endl << endl;
                cout << ">>>What would you like to do? ";

                userIn = getValidInput("1|2|3|4");

                if (userIn == "1")
                     //play the guess number game
                     GuessNumber();

                else if (userIn == "2")
                     //play the palindrome game
                     PalindromeChallenge();

                else if (userIn == "3")
                     //play the die rolling game
                     BiasedDieChallenge();
           }
           else {
                cout << endl << "You do not have enough money to gamble!!" << endl;
                userIn = "4";
           }

      } while (userIn != "4");

      //take the end time
      time(&outStore);

      //adjust the time remaining for the character
      int timeSpent = (int)difftime(outStore, inStore);
      user1->AdjustTime(0 - timeSpent / 5);       //every 5 seconds equal 1 min 

}
 