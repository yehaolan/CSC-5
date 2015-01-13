/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 9:21 PM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal15)
 */

//System Libraries
#include <iostream>
#include <cstdlib> //random rand(),srand()
using namespace std;

//User libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //declare and set the value for 2 number between 100 and 999
    short num1 = rand()%900+100;
    short num2 = rand()%900+100;
    
    //display the question
    cout << "The question is: " <<endl;
    cout << "When you are ready to check the answer, press Enter key.\n";
    cout << "    " << num1 << endl;
    cout << "  + " << num2 << endl;
    cout << "   -----";
    cin.ignore(); //pause the program until press Enter key
    
    //display the answer of addition
    cout << "   " << (num1+num2) <<endl;
    
    return 0;
}

