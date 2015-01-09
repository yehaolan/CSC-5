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
const char CONVPCT = 100;

//Function Prototype

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    char divPer = 62;//the percentage of division from sales
    int sales = 4.6E6;//total sales = 4.6million dollars
    int division;//(dollars)
    
    //Introduce the percentage of sales division from total sales
    cout << "The East Coast sales division of a company generates\n";
    cout << "62% percent of the total sales.";
    //The total sales of this year
    cout << "This company has $4.6 million in sales this year.\n";
    
    //Calculate the division
    division = sales*divPer/CONVPCT;
    
    //Output the result
    cout << "The East Coast will generate about $" << division << " division.\n";
    
    //Exit stage right!
    return 0;
}

