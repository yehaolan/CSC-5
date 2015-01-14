/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 14, 2015, 11:02 AM
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
    int choice;
    //Assignment 2 Menu Prompt
    cout << "Solution 1 Savitch 8thEd Chap2 Prob2" << endl;
    cout << "Solution 2 Savitch 8thEd Chap2 Prob6" << endl;
    cout << "You get the idea" << endl;
    cout << "Input which solution you would like to see?" << endl;
    cin >> choice;
    //Base on the choice, display the results
    switch(choice) {
        case 1: {
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
            break;
        }
        case 2:{
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
                } 
                else {
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
            break;
        }
        default: cout << "Incorrect choice!" << endl;
    }    
    //Exit stage right
    return 0;
}

