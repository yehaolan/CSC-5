/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 7, 2015, 11:43 PM
 * Purpose: Homework assignment(Savitch_8thEd_Chap1_ProgProj5)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare 2 variables
    short num1,//First integer
          num2,//Second integer
          sum,//Sum of first and second integer
          prod;//Product of first and second integer
    
    //Prompt user for two integer
    cout << "Input two integers:" << endl;
    cin >> num1 >> num2;
    
    //Calculate the sum and product of first and second number
    sum = num1 + num2;
    prod = num1 * num2;
    
    //Output the results
    cout << num1 << " + " << num2 << " = " << sum << endl;
    cout << num1 << " * " << num2 << " = " << prod << endl;
    
    //Last output statement
    cout << "This is the end of the program.\n";
    
    //Exit stage right
    return 0;
}

