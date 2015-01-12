/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 11, 2015, 10:11 PM
 * Purpose: Homework Assignment(Gaddis_7thEd_Chap3_ProgChal1)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float gas,//the number of gallons of gas the car can hold
          dist,//distance in miles that the car can drive with full tank
          mpg;//mile per gallon of gas
    
    //Introduce this program
    cout << "This program can calculate a car's gas mileage.\n";
    
    //Prompt user for gas and distance
    cout << "Please input the capacity of car tank.\n";
    cin >> gas;
    cout << "Please input the distance that the car can go with full tank.\n";
    cin >> dist;
    cout << endl;
    
    //calculate the result
    mpg = dist/gas;
    
    //Output the result
    cout << "The number of miles that may be" << endl;
    cout << "driven per gallon of gas is " << mpg << ".\n";
    
    //Exit stage right
    return 0;
}

