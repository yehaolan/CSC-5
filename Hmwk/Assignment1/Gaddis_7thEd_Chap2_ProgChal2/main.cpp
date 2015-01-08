/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on January 6, 2015, 3:00 PM
 * Purpose:Homework assignment (Gaddis_7thEd_Chap2_ProgChal2)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float percentage = 0.62;//62%
    unsigned int sales = 4.6E6;//total sales = 4.6million dollars
    unsigned int division;//(dollars)
    
    //Introduce the percentage of sales division from total sales
    cout << "The East Coast sales division of a company generates\n";
    cout << "62% percent of the total sales.";
    //The total sales of this year
    cout << "This company has $4.6 million in sales this year.\n";
    
    //Calculate the division
    division = sales * percentage;
    
    //Output the result
    cout << "The East Coast will generate about $" << division << " division.\n";
    
    //Exit stage right!
    return 0;
}

