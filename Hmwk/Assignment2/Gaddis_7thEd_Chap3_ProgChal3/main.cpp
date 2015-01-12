/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 11, 2015, 10:33 PM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal3)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short scr1,scr2,scr3,scr4,scr5;//5 scores that user input
    float avge;//average of 5 scores
    
    //Prompt user for 5 scores
    cout << "Please input five test scores.\n";
    cin >> scr1 >> scr2 >> scr3 >> scr4 >> scr5;
    
    //Calculate average
    avge = static_cast<float>(scr1 + scr2 + scr3 + scr4 + scr5)/5;
    
    //Output the formated result 
    cout << setprecision(1) << fixed;
    cout << "The average test score is " << avge << endl;
    //Exit stage right
    return 0;
}

