/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on January 15, 2015, 4:12 PM
 * Purpose:Homework assignment(Gaddis_7thEd_Chap4_ProgChal19)
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
const float CAR_DIO = 258.0;//speed of sound in carbon dioxide
const float AIR = 331.5;//speed of sound in air
const float HELIUM = 972.0;//speed of sound in helium
const float HYDGN = 1270.0;//speed of sound in hydrogen

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char select;//which choice user select
    short time;//the time of sound go through
    float dist;//the distance of sound have gone through
    string medium;//the string of 4 medium
    float speed;//the speed of sound in a certain medium
    
    //introduce the program and display the menu for user to select
    cout << "This program can calculate the distance of " << endl;
    cout << "sound go through in certain time." << endl;
    cout << "***************The Gas Menu***************" << endl;
    cout << "1. Carbon Dioxide" << endl;
    cout << "2. Air" << endl;
    cout << "3. Helium" << endl;
    cout << "4. Hydrogen" << endl;
    
    do {
        cout << "Please input 1-4 for selecting" << endl;
        cin >> select;
    } while(select<'1'||select>'4');
    //select the medium
    
    switch(select) {
        case '1'://carbon dioxide
            medium = "carbon dioxide";
            speed = CAR_DIO;
            break;
        case '2'://air
            medium = "air";
            speed = AIR;
            break;
        case '3'://helium
            medium = "helium";
            speed = HELIUM;
            break;
        case '4'://hydrogen
            medium = "hydrogen";
            speed = HYDGN;
            break;
        default://tell user it is invalid choice
            cout << "This is invalid choice." << endl;
            cout << "Please run this program again and select from 1 - 4." << endl;
    }
    //tell user which medium has been selected, and prompt user for time
    cout << "You have selected " << medium << endl;
    cout << "Input the time of sound travels(seconds)" << endl;
    cout << "Please input a positive integer between 0 and 30" << endl;
    //require the time is between 0 and 30 seconds
    do {
        cin >> time;
        if(time<0||time>30)
            cout << "Please input the time between 0 and 30 seconds" << endl;
    } while(time<0||time>30);
    
    //calculate the distances
    dist = time*speed;
    
    //Output the result
    cout << "The distance of sound went through in " << medium  << endl;
    cout << "in " << time << " seconds is " << dist << " meters" << endl;
    //Exit stage right
    return 0;
}

