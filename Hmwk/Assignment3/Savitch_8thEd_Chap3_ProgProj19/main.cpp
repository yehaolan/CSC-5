/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 20, 2015, 10:29 AM
 * Purpose: game of "23"
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
    char thPick=23;//toothpick
    bool computer=false;
    short nPckRmv;//number of toothpick want to remove
    //Play the game
    do {
        //designate the player
        computer=false;
        //ask player how many toothpicks
        do {
            cout<<"There are "<<static_cast<int>(thPick)<<" left to remove"<<endl;
            cout<<"How many toothpick do you want to remove"<<endl;
            cout<<"Choose 1,2,or 3"<<endl;
            cin>>nPckRmv;
        }while(nPckRmv<0||nPckRmv>=4||nPckRmv>thPick);
        //remove the number of toothpick
        thPick-=nPckRmv;
        //Designate the computer
        computer=true;
        //Utilize logic from the book
        if(thPick>4) {
            nPckRmv=4-nPckRmv;
            thPick-=nPckRmv;
        } else if(thPick>=2&&thPick<=4) {
            thPick=1;
        } else if(thPick==1) {
            thPick=0;
            computer=false;
        }
    }while(thPick>1);
    
    //Output the loser and winner
    if(computer){
        cout<<"Computer wins you lose"<<endl;
    } else {
        cout<<"Computer loses you win"<<endl;
    }
    
    //Exit the game
    return 0;
}

