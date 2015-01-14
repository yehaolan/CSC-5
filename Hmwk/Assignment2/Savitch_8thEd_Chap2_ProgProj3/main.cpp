/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 13, 2015, 9:41 AM
 * Purpose: homework assignment(Savitch_8thEd_Chap2_ProgProj3)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float PYINCS = 0.076;
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int preAnSlr; //previous annual salary
    float rtrPay,//the amount of retroactive pay due the employee
          nwAnSlr,//the new annual salary
          nwMnSlr;//the new monthly salary
    char ans;//the answer of whether run this program again
    
    
    do {
        //Prompt user for previous annual salary
        cout << "Your previous annual salary(dollar): " << endl;
        cout << "Please input a positive integer." << endl;
        cin >> preAnSlr;
        
        //calculate the results
        rtrPay = PYINCS*preAnSlr;
        nwAnSlr = preAnSlr + rtrPay;
        nwMnSlr = nwAnSlr/12;
        
        //Formatted output the results
        cout << setprecision(2) << fixed;
        cout << "Your retroactive pay is $" << rtrPay << endl;
        cout << "Your new annual salary is $" << nwAnSlr << endl;
        cout << "Your new monthly salary is $" << nwMnSlr << endl;
        
        //Ask if user want to repeat the program
        cout << "Would you like to repeat this program?" << endl;
        cout << "Type Y for yes and N for no." << endl;
        cin >> ans;
    } while(ans=='Y'||ans=='y'); //when answer is 'y' or 'Y',run it again
    
    //Exit stage right
    return 0;
}

