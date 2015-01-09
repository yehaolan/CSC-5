/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 10:33 AM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap2_ProgChal10)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char gas = 12;//gallons of gasoline
    short dist=350;//distance(miles)before refueling
    float mpg;//miles per gallon
    //introduce this program
    cout << "This program calculate the number of miles per gallon the car gets.\n";
    cout << "A car holds 12 gallons of gasoline and" << endl;
    cout << "Can travel 350 miles before refueling." << endl;
    
    //calculate the result
    mpg=static_cast<float>(dist)/gas;
    
    //Output the result
    cout << setprecision(4);
    cout << "So, a car with per gallon gasoline can drive "<< mpg << " miles.\n";
    
    //Exit stage here
    return 0;
}

