/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 27, 2015, 12:32 PM
 * Purpose: Project1(Name of the game:Bomb Password)
 */

//system Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string toDash(int);//
void introduce();//introduce the game
void ask(char& guess,int& digit);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned short>(time(0)));
    //declare variables
    const int TOTGUESS=15;//total chance of the game
    const int SIZE=4;//the size of the char array
    string dash;
    string answer;
    int gusCorr;//how many correct number have been guessed 
    int chnslft;//chance Counter(how many many)
    int digit;
    char guess;
    char pswd[SIZE];//the password store in the array
    
    //introduce the game
    introduce();
    cout<<"Press Enter to start the game";
    cin.ignore();
    
    //get a random 4-digit password and put it in array
    for(int i=0;i<SIZE;i++) {
        pswd[i]=rand()%10+48;
    }
    
    dash=toDash(SIZE);
    
    
    
    cout<<"Now look like this: "<<dash<<endl;
    for(int i=0;i<SIZE;i++) {
        answer+=pswd[i];
    }
    cout<<answer;
    //Exit stage right
    return 0;
}

string toDash(int size) {
    string dashed="";
    for(int i=0;i<size;i++) {
        dashed+="-";
    }
    return dashed;
}

void introduce() {
    
}

void ask(char& guess,int& digit) {
    do {
        cout<<"Please input the number you guess"<<endl;
        cin>>guess;
        cin.ignore();
        if(guess<48||guess>57)
            cout<<"Invalid input"<<endl;
    } while(guess<48||guess>57);
    do {
        cout<<"Please input the digit of this number"<<endl;
        cin>>digit;
        cin.ignore();
        if(digit<1||digit>4)
            cout<<"Invalid input"<<endl;
    } while(digit<1||digit>4);
}