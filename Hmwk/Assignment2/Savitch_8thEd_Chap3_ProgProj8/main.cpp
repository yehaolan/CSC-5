/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 17, 2015, 9:55 PM
 * Purpose: Homework assignment2(Savitch_8thEd_Chap3_ProgProj8)
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
    short crdNum;//the number of cards user has
    
    //introduce program and prompt user for the number of cards he has
    cout << "This program scores a blackjack hand" << endl;
    do {
        cout << "How many cards you have?(an integer between 2 and 5)";
        cin >> crdNum;
        if(crdNum<2||crdNum>5)
            cout << "The range is from 2 to 5" << endl;
    } while(crdNum<2||crdNum>5);
    //Exit stage here
    return 0;
}

