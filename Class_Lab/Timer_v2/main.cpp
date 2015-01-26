/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 26, 2015, 10:04 AM
 * Purpose: timer
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Initialize the random number seed 
    srand(static_cast<unsigned short>(time(0)));
    //declare variables
    unsigned int x, y,begTim,endTim,ans,totTim;
    //randomly choose 2 digits for each
    x=rand()%90+10;
    y=rand()%90+10;
    totTim=5;
    begTim=static_cast<unsigned int>(time(0));
    //Prompt user for an answer
    cout<<"What is "<<x<<" + "<<y<<endl;
    cout<<"You have "<<totTim<<" seconds to answer"<<endl;
    cin>>ans;
    endTim=static_cast<unsigned int>(time(0));
    if(totTim>endTim-begTim) {
        if(ans==(x+y)) cout<<"You are correct"<<endl;
        else cout<<"You are wrong"<<endl;
    } else {
        cout<<"You took too much time"<<endl;
        cout<<"Time allowed = "<<totTim<<endl;
        cout<<"Your time = "<<endTim-begTim<<endl;
    }
    //Determine correct
    
    //Exit stage right
    return 0;
}


