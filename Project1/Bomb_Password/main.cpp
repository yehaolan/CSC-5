/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 27, 2015, 12:32 PM
 * Purpose: Project1(Name of the game:Bomb Password)
 */

//system Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned short>(time(0)));
    //declare variables
    const int TOTGUESS=15;//total chance of the game
    const int SIZE=4;//the size of the char array
    string dash;
    string answer;
    int gusCorr;//how many correct number have been guessed 
    int chnslft;//chance Counter(how many many)
    int digit;
    char guess;
    char pswd[SIZE];//the password store in the array
    //Exit stage right
    return 0;
}

