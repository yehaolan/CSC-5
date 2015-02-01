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
#include <vector>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string toDash(int);//change the password to dash
void introduce();//introduce the game
void ask(char&,int&);
char check(char,int,const char[],int);
bool indexOf(char,const char[],int);
void replace(string& dash,char guess,int digit);
bool inside(const vector<int>,int);
void sample();

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned short>(time(0)));
    //declare a file object
    ofstream output;
    
    //open the file
    output.open("Times.dat");
    
    //declare and initialize variables
    const int TOTCHNS=15;//total chance of the game
    const int SIZE=4;//the size of the char array
    string dash;
    string answer;
    int times=0;  //how many times user tried
    int gusCorr=0;//how many correct number have been guessed 
    int chnsLft;  //chance counter(how many chances left)
    int digit=0;  //digit of the user guesses
    char guess=0; //the number user guesses
    char pswd[SIZE]={};//the password store in the array
    vector<int> inputDg(SIZE,5);//the digits finished
    
    //introduce the game
    introduce();
    cout<<"Press Enter to start the game";
    cin.ignore();
    
    //get a random 4-digit password and put it in array
    for(int i=0;i<SIZE;i++) {
        pswd[i]=rand()%10+'0';
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
            case'1': { //if the number and place both are correct
                replace(dash,guess,digit);
                if(inside(inputDg,digit)) {
                    cout<<"You already finish this digit,"
                        <<"try other digit"<<endl;
                } else {
                    inputDg.push_back(digit-1);//record the digit which has been finished
                    cout<<"Your guess is correct."<<endl;
                    gusCorr++;
                }
                break;
            }
            case'2': { //if number is correct but digit is wrong
                cout<<"This is the correct number but in wrong place."<<endl;
                chnsLft--;
                break;
            }
            case'3': { //if number and digit both wrong
                cout<<"Wrong number and wrong place."<<endl;
                chnsLft--;
                break;
            }
            default:;
        }
        times++;//keep track of how many times user have input
    }
    if(chnsLft==0) {
        cout<<"You lost"<<endl;
        output<<"You lost"<<endl;
    }
    if(gusCorr==SIZE) {
        output<<"You win this game after "<<times<<" tries"<<endl;
        cout<<"You win this game after "<<times<<" tries"<<endl;
    }
    cout<<"The answer is "<<answer;
    output.close();
    
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
        cout<<"If you need sample for input, type \'s\'"<<endl;
        cin>>guess;
        cin.ignore();
        if(guess=='s'||guess=='S')
            sample();
        if(guess<48||guess>57||guess!='s'||guess!='S')
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

bool inside(const vector<int> inputDg,int digit) {
    bool temp=false;
    for(int i=0;i<inputDg.size();i++) {
        if(inputDg[i]==(digit-1))
            temp=true;
    }
    return temp;
}

void sample() {
    string str;
    ifstream input;
    input.open("Sample.dat");
    while(input>>str) {
        if(str=="Now"||str=="If"||str=="You")
            cout<<endl;
        cout<<str<<' ';
    }
    cout<<endl<<endl;
    input.close();
}