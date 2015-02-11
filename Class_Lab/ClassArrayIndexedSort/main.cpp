/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 9, 2015, 9:26 AM
 * Purpose: Test the Array ADT
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array ADT
    int size=100,perLine=10;
    //declare a Array Object
    Array array;
    array.filAray(size);
    //Sort the array
    array.mrkSort();
    //Print the array
    array.prntAry(perLine);
    //Clean up
    array.destroy();
    //Exit stage right
    return 0;
}
