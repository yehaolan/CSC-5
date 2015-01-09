/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 8, 2015, 9:40 AM
 * Purpose:Homework assignment(Gaddis_7thEd_Chap2_ProgChal4)
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
    //declare variables
    float mlcrg=44.5,//meal charge
          taxPer=0.0675,//percentage of tax from meal cost
          tipPer=0.15,//percentage of tip from total after adding tax
          tax,//tax amount
          tip,//tip amount
          total;//total bill
    
    //calculate the tax,tip, and total amount
    tax = mlcrg*taxPer;
    tip = (tax+mlcrg)*tipPer;
    total = mlcrg+tax+tip;
    
    //format output the results
    cout << setprecision(2) << fixed;
    cout << "The meal cost  is $" << mlcrg << endl;
    cout << "The tax amount is $" << tax << endl;
    cout << "The tip amount is $" << tip << endl;
    cout << "The total bill is $" << total << endl;
    
    //Exit stage right
    return 0;
}

