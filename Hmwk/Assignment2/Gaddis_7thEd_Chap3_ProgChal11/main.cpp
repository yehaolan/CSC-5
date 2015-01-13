/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 1:20 PM
 * Purpose:bitcoin conversion
 */

//System libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float YN_P_DOL = 119.54;  //Yen per dollar 
const float ER_P_DOL = 0.85;    //Euros per dollar
//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables and initialize
    float bcToDlr=232.8;    //Jan 13th,2015 10:17am
    float erToDlr=0.849381; //same date
    float ynToDlr=118.03;   //Same date
    float bitcoin,dollars,euros,yen;
    
    //Input the number of bitcoin and then convert
    cout << "Input the number of bitcoin " << endl;
    cout << "You wish to purchase." << endl;
    cin >> bitcoin;
    //convert to all the currencies
    dollars = bcToDlr*bitcoin;
    euros = erToDlr*dollars;
    yen = ynToDlr*dollars;
    //Output the results
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << bitcoin << " = " << dollars << "(dollars)" << endl;
    cout << bitcoin << " = " << euros << "(euros)" << endl;
    cout << bitcoin << " = " << yen << "(yen)" << endl;
    //exit stage right
    return 0;
}

