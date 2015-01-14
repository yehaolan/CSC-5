/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 14, 2015, 7:28 AM
 * Purpose: Homework assignment(Savitch_8thEd_Chap2_ProgProj6)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    unsigned short capcty, //the capacity of the meeting room
                   attend; //the number of people attending meeting
    short difenc; // difference between capacity and the number of attending
    char ans;     //answer for whether repeat program
    //introduce the program
    cout << "This program determines whether a meeting room is in violation of " << endl;
    cout << "fire law regulations regarding the maximum room capacity."  <<endl;
    
    do {
        //Prompt user for capacity and attending people
        cout << endl;
        cout << "Input the meeting room capacity:" << endl;
        cout << "Please input a positive integer." << endl;
        cin >> capcty;
        cout << "Input the number of people attending the meeting:" << endl;
        cout << "Please input a positive integer." << endl;
        cin >> attend;

        //calculate the difference capacity and the number of attending
        difenc = capcty - attend;

        //determine whether the attending number is over capacity,and output the result
        if(difenc>=0) {
            cout << "It is legal to hold the meeting." << endl;
            cout << difenc << " additional people may legal attend." << endl;
        } else {
            cout << "The meeting cannot be held as planned due to fire regulations." << endl;
            cout << (-difenc) << " people must be excluded in order ";
            cout << "to meet the fire regulations." << endl;
        }
        //Ask if repeat the program
        cout << endl;
        cout << "Would you like to repeat this program?" << endl;
        cout << "Type Y for yes and N for no." << endl;
        cin >> ans;
    } while(ans=='Y' || ans=='y');
    
    
    
    //Exit stage right
    return 0;
}

