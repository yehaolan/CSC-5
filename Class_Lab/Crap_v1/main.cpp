/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Modified by: Haolan Ye(Benjamin)
 * Created on January 27, 2015, 8:45 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int rollDie(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    unsigned int nGames=1000000,nDie=2;
    int win=0,loss=0,nThrows=0,maxThrow=0;
    //Play the game
    for(unsigned int game=1;game<=nGames;game++){
        //Throw the dice
        int sum1=rollDie(nDie),gThrow=0;
        nThrows++;gThrow++;
        //Win-Loss or keep rolling
        if(sum1==7||sum1==11)win++;
        else if(sum1==2||sum1==3||sum1==12)loss++;
        else{
            //Keep rolling until you stop
            bool stop=false;
            do{
                //Roll the die 
                int sumN=rollDie(nDie);
                nThrows++;gThrow++;
                //Check for win or loss
                if(sumN==7){
                    loss++;
                    stop=true;
                }else if(sumN==sum1){
                    win++;
                    stop=true;
                }
            }while(!stop);
        }
        if(gThrow>maxThrow)maxThrow=gThrow;
    }
    //Output
    cout<<"Games played = "<<nGames<<endl;
    cout<<"Wins = "<<win<<endl;
    cout<<"Loss = "<<loss<<endl;
    cout<<"Total Win/Loss = "<<win+loss<<endl;
    cout<<"Percent wins = "<<100.0f*win/nGames<<"%"<<endl;
    cout<<"Percent loss = "<<100.0f*loss/nGames<<"%"<<endl;
    cout<<"Averaqe Throws/Game = "<<1.0f*nThrows/nGames<<endl;
    cout<<"During one of the games a set of dice was thrown "
        <<maxThrow<<"(times)"<<endl;
    //Exit stage right
    return 0;
}

int rollDie(int nDice){
    //Declare variables
    int sum=0;
    for(int roll=1;roll<=nDice;roll++){
        sum+=(rand()%6+1);
    }
    return sum;
}

