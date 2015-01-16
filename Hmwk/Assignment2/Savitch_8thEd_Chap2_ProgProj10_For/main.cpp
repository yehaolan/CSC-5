/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on January 15, 2015, 10:27 AM
 * Purpose:Homework assignment(Savitch_8thEd_Chap2_ProgProj10)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int sum=0,sumNeg=0,sumPos=0,sumEven=0,sumOdd=0;
    int input;
    
    for(int count=1;count<=10;count++){
        //Prompt for a value and sum it
        cout << endl<<"Input an integer value!"<< endl;
        cin >> input;
        sum+=input;
        if(input>0) sumPos+=input;
        else sumNeg+=input;
        if(input%2) sumOdd+=input;
        else sumEven+=input;
    }
    
    
    //Output the results
    cout << "Sum          = " << sum << endl;
    cout << "Positive Sum = " << sumPos << endl;
    cout << "Negative Sum = " << sumNeg << endl;
    cout << "Even Sum     = " << sumEven << endl;
    cout << "Odd Sum      = " << sumOdd << endl;
    
    return 0;
}

