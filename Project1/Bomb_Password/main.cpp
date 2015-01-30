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
void ask(char&,int&);
char check(char,int,const char[],int);
bool indexOf(char,const char[],int);
void replace(string& dash,char guess,int digit);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned short>(time(0)));
    //declare and initialize variables
    const int TOTCHNS=15;//total chance of the game
    const int SIZE=4;//the size of the char array
    string dash;
    string answer;
    int gusCorr=0;//how many correct number have been guessed 
    int chnsLft;//chance Counter(how many many)
    int digit=0;
    char guess=0;
    char pswd[SIZE]={};//the password store in the array
    
    //introduce the game
    introduce();
    cout<<"Press Enter to start the game";
    cin.ignore();
    
    //get a random 4-digit password and put it in array
    for(int i=0;i<SIZE;i++) {
        pswd[i]=rand()%10+48;
    }
    
    dash=toDash(SIZE);
    chnsLft=TOTCHNS;
    
    for(int i=0;i<SIZE;i++) {
        answer+=pswd[i];
    }
    cout<<answer;
    //game begins
    while(chnsLft>0&&gusCorr<SIZE) {
        //Prompt user for the guess
        cout<<endl;
        cout<<"The password now looks like this: "<<dash<<endl;
        cout<<"You have "<<chnsLft<<" chances left"<<endl;
        ask(guess,digit);
        char result=check(guess,digit,pswd,SIZE);
        switch(result) {
            case'1': {
                replace(dash,guess,digit);
                cout<<"Your guess is correct. Keep going!"<<endl;
                gusCorr++;
                break;
            }
            case'2': {
                cout<<"This is the correct number but in wrong place."<<endl;
                chnsLft--;
                break;
            }
            case'3': {
                cout<<"Wrong number and wrong place."<<endl;
                chnsLft--;
                break;
            }
            default:;
        }
    }
    if(chnsLft==0)
        cout<<"You lost"<<endl;
    if(gusCorr==SIZE)
        cout<<"You win"<<endl;
    
    
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

char check(char guess,int digit,const char pswd[],int size) {
    if(guess==pswd[digit-1]) {
        return '1';
    } else if(indexOf(guess,pswd,size)) {
        return '2';
    } else {
        return '3';
    }
}

bool indexOf(char x,const char pswd[],int size) {
    bool temp=false;
    for(int i=0;i<size;i++) {
        if(pswd[i]==x)
            temp=true;
    }
    return temp;
}

void replace(string& dash,char guess,int digit) {
    string part1=dash.substr(0,(digit-1));
    string part2=dash.substr(digit);
    dash=part1+guess+part2;
}