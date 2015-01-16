/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 13, 2015, 11:35 AM
 * Purpose: Babylonian Square root calculator
 * New version to utilize loops
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    float number,guess,r;
    short count = 0;
    //input a number
    cout << "Input a number to estimate it's square root"<<endl;
    cout << "The format fill be a float positive float" <<endl;
    cin >> number;
    //first pass
    guess = number/2;
    do {
        r = number/guess;
        guess = (guess+r)/2;
        count++;
        //Output the first pass
        cout << "Loop "<< count <<"  -> " << guess << endl;
    //}while(guess!=r); //My preferred technique
    }while(abs(guess-r)>0.01);
    //Exit stage right
    return 0;
}

