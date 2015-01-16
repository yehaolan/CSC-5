/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on January 15, 2015, 3:27 PM
 * Purpose:Homework assignment(Gaddis_7thEd_Chap4_ProgChal10)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char CONVPT = 100;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short retail = 99;//the retail of a package($)
    short unit;//the number of units sold
    float cost;//total cost of the purchase
    char dscnt;//quantity discount
    //Prompt user for the number of units
    do {
      cout << "How many unit of package have been sold?" <<endl;
      cin >> unit;
      if(unit<=0)
          cout << "Please input the positive number" << endl;
    } while(unit<=0);//make sure the number of unit is positive
    //determine the discount
    if(unit>=100) {
        dscnt = 50;
    } else if(unit>=50) {
        dscnt = 40;
    } else if(unit>=20) {
        dscnt = 30;
    } else if(unit>=10) {
        dscnt = 20;
    } else {
        dscnt = 0;
    }
    //calculate the total cost
    cost = retail*unit*(1-static_cast<float>(dscnt)/CONVPT);
    //Output the result
    cout << setprecision(2) << fixed;
    cout << "The total cost of the purchase is $" << cost << endl;
    
    //Exit stage right
    return 0;
}

