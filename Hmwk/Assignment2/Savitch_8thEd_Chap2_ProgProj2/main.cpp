/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 14, 2015, 10:19 AM
 */

//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global Constants
const float CNVLBGM= 453.6;
//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const float CONC = 1e-3f;//sweetener concentration
    float wtCoke=3.5e2f;//weight of coke in grams
    float kMouse = 5.0f,//quantity of sweetener that kills a mouse
          wtMouse=3.5e1f,//weight of mouse that kills a mouse in grams
          kPer,
          wtDsPer;
    int nCans;
    //Input the desire weight of person
    cout << "Input your desire weight in lbs" << endl;
    cout << "Format the input as a float" << endl;
    cin >> wtDsPer;
    wtDsPer*=CNVLBGM;
    //calculation
    kPer = kMouse/wtMouse*wtDsPer;
    nCans = kPer/wtCoke/CONC;
    //Output the limit of what you can drink
    cout << "Number of cans of diet coke that will kill you = " << nCans << endl;
    
    //Exit stage right
    return 0;
}

