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

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    unsigned short qrts,//the number of quarters
                   dimes,//the number of dimes
                   nic,//the number of nickels
                   value;//the monetary value of coins in cents
    //introduce this program
    cout << "This program can calculate the monetary value of" << endl;
    cout << "The quarters, dimes, and nickels in cents." << endl;
    
    //Prompt user for the number of quarters, dimes, and nickels
    cout << "Input the number of quarters, dimes, and nickels.\n";
    cin >> qrts >> dimes >> nic;
    
    //calculate the monetary value of these coins
    value = qrts*25 + dimes*10 + nic*5;
    
    //Output the results
    cout << "The coins are worth " << value << " cents." << endl;
    
    //Exit stage right
    return 0;
}

