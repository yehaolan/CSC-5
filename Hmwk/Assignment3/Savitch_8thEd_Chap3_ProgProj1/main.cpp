/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 1:58 PM
 * Purpose:Homework assignment(Savitch_8thEd_Chap1_ProgProj1)
 * Paper-rock-scissor game
 * Only use char in the program
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
    char p1,//player1
         p2;//player2
    //introduce the program
    cout<<"Paper-rock-scissor game"<<endl;
    cout<<"After input two players' gesture, this program can determine who win"<<endl;
    //prompt user for first player's gesture
    do{
        cout<<"Input the first player's gesture"<<endl;
        cout<<"Note:Only input P,R, or S"<<endl;
        cin>>p1;
        if(p1!='p'&&p1!='r'&&p1!='s'&&p1!='P'&&p1!='R'&&p1!='S')
            cout<<"Invalid input"<<endl;
    }while(p1!='p'&&p1!='r'&&p1!='s'&&p1!='P'&&p1!='R'&&p1!='S');
    //if it is upper case,change it to lowercase
    if(p1<91)
        p1+=32;
    //prompt user for second player's gesture
    do{
        cout<<"Input the second player's gesture"<<endl;
        cout<<"Note:Only input P,R, or S"<<endl;
        cin>>p2;
        if(p2!='p'&&p2!='r'&&p2!='s'&&p2!='P'&&p2!='R'&&p2!='S')
            cout<<"Invalid input"<<endl;
    }while(p2!='p'&&p2!='r'&&p2!='s'&&p2!='P'&&p2!='R'&&p2!='S');
    //if it is upper case,change it to lowercase
    if(p2<91)
        p2+=32;
    //compare two gesture
    if(p1==p2){
        //when they equal,nobody wins
        cout<<"Nobody wins"<<endl;
    } else if(p1+p2==226){
        //when sum is 226, means paper and rock
        cout<<"Paper cover rock"<<endl;
        if(p1==112)
            //when p1 is paper
            cout<<"Player1 win"<<endl;
        else
            //when p1 is not paper
            cout<<"Player2 win"<<endl;
    } else if(p1+p2==227){
        //when sum is 227, means paper and scissors
        cout<<"Scissors cut paper"<<endl;
        if(p1==115)
            //when p1 is scissor
            cout<<"Player1 win"<<endl;
        else
            //when p1 is not scissor
            cout<<"Player2 win"<<endl;
    } else {
        //in other situation,means rock and scissor
        cout<<"Rock breaks scissors"<<endl;
        if(p1==114)
            //when p1 is rock
            cout<<"Player1 win"<<endl;
        else
            //when p1 is not rock
            cout<<"Player2 win"<<endl;
    }
    
    //Exit stage right
    return 0;
}

