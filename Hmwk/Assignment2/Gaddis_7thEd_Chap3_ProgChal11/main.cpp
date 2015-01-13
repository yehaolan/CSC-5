/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 1:20 PM
 * Purpose:Homework assignment(Gaddis_7thEd_Chap3_ProgChal11)
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
    //declare variables
    unsigned short dol;//the amount in dollars need to exchange
    float yen,euro;//the amount in yen and euro after exchanging
    //prompt user for the amount of dollar needing to exchange
    cout << "How much dollar you want to exchange to Yen and Euros.\n";
    cout << "Please input an integer between 0 and 1000\n";
    cin >> dol;
    //calculate the result
    yen = dol*YN_P_DOL;
    euro = dol*ER_P_DOL;
    //output the result
    cout << setprecision(2)<< fixed;
    cout << dol << " dollars exchanges to Yen is  " << yen << " yen.\n";
    cout << dol << " dollars exchanges to Euro is " << euro << " euros.\n";
    //exit stage here
    return 0;
}

