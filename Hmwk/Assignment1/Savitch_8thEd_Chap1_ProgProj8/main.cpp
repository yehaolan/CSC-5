/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 12:07 AM
 * Purpose:homework assignment(Savitch_8thEd_Chap1_ProgProj8)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
const char VALQTR=25;//Value of a quarter=25 
const char VALDIME=10;//Value of a quarter=25 
const char VALNIC=5;//Value of a quarter=25 

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char qrts,//the number of quarters
         dimes,//the number of dimes
         nic;//the number of nickels
    short  value;//the monetary value of coins in cents
    //introduce this program
    cout << "This program can calculate the monetary value of" << endl;
    cout << "The quarters, dimes, and nickels in cents." << endl;
    
    //Prompt user for the number of quarters, dimes, and nickels
    cout << "Input the number of quarters, dimes, and nickels.\n";
    cout << "The range of the number you input is from 0 to 9" << endl;
    cin >> qrts >> dimes >> nic;
    
    //calculate the monetary value of these coins
    value = static_cast<unsigned short>((qrts-48)*VALQTR + (dimes-48)*VALDIME + (nic-48)*VALNIC);
    
    //Output the results
    cout << "The coins are worth " << value << " cents." << endl;
    
    //Exit stage right
    return 0;
}

