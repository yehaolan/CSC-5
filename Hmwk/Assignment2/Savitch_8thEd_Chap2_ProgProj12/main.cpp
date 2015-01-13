/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 13, 2015, 11:35 AM
 * Purpose: Babylonian Square root calculator
 */

//System Libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float number,guess,r;
    //input a number
    cout << "Input a number to estimate it's square root"<<endl;
    cout << "The format fill be a float positive float" <<endl;
    cin >> number;
    //first pass
    guess = number/2;
    r = number/guess;
    guess = (guess+r)/2;
    //Output the first pass
    cout << "First pass calculate -> " << guess << endl;
    
    //second pass
    r = number/guess;
    guess = (guess+r)/2;
    //Output the second pass
    cout << "Second pass calculate -> " << guess << endl;
    
    //Third pass
    r = number/guess;
    guess = (guess+r)/2;
    //Output the third pass
    cout << "Third pass calculate -> " << guess << endl;
    
    //fourth pass
    r = number/guess;
    guess = (guess+r)/2;
    //Output the fourth pass
    cout << "Fourth pass calculate -> " << guess << endl;
    
    //Exit stage right
    return 0;
}

