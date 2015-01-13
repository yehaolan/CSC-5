/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on January 12, 2015, 10:17 PM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal16)
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global constants
const char CONVPT = 100;

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float intRate, //interest rate
          prnp,    //principal
          intrst,  //interest
          saving;  //amount in savings
    short tmCmp;   //the number of times that the interest is compounded
    
    //Prompt user for interest rate,time compounded,and principal
    cout << "Interest Rate: " << endl;
    cout << "Please input a number in percent.\n";
    cin >> intRate;
    cout << "The times compounded: " << endl;
    cout << "Please input an integer greater than 0" <<endl;
    cin >> tmCmp;
    cout << "Principal(dollar): ";
    cout << "Please input a number greater than 1." <<endl;
    cin >> prnp;
    
    //calculate the results
    saving = prnp*pow((1+intRate/tmCmp/CONVPT),tmCmp);
    intrst = saving - prnp;
    
    //Formatted output the results
    cout << setprecision(2) << fixed;
    cout << "Interest Rate:       " << setw(7) << intRate << "%" << endl;
    cout << "Times Compounded:    " << setw(7) << tmCmp << endl;
    cout << "Principal:          $" << setw(7) << prnp << endl;
    cout << "Interest:           $" << setw(7) << intrst << endl;
    cout << "Amount in Savings:  $" << setw(7) << saving << endl;
    //exit stage here
    return 0;
}

