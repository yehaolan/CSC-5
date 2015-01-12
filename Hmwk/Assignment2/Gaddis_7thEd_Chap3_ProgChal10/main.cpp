/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 8:28 AM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal10)
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
    //declare variable
    short cls;//Celsius Temperature
    float fhe;//Fahrenheit temperatures
    
    //introduce the program
    cout << "This program converts Celsius temperatures ";
    cout << "to Fahrenheit temperatures." << endl;
    
    //Prompt user for Celsius temperatures
    cout << "Input Celsius temperatures.\n";
    cout << "Please input an integer between 0 and 100.\n";
    cin >> cls;
    
    //calculate the results
    fhe=9.0f/5*cls+32;
    
    //formatted output the result
    cout << setprecision(1) << fixed;
    cout << "The temperature you entered " ;
    cout << "in Fahrenheit is "<< fhe << " degrees.\n";
    
    //Exit stage right
    return 0;
}

