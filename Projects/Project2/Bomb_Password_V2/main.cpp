/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 27, 2015, 12:32 PM
 * Purpose: Project1(Name of the game:Bomb Password)
 */

//system Libraries
#include <iostream>
#include <cstdlib>  //for random number
#include <string>     
#include <vector>
#include <fstream>  //file I/O
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
string toDash(int);//change the password to dash
void introduce();//introduce the game
void gtPswd(char [],int,const int,const int);
void ask(char&,int&,int,int,vector<int>,char [],int &);//ask user for guessing
char check(char,int,const char[],int);//check whether number and digit are correct
bool indexOf(char,const char[],int);//return whether the char is in the char array
void replace(string&,char,int);//replace of the correct digit
bool inside(const vector<int>,int);//return whether this digit is finished
void sample();//display the sample of guessing
void hint(vector<int>,char [],int);
int bin(int);//change an integer to binary
void record(int);//save the top 10 player record 

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned short>(time(0)));
    //declare a file object
    ofstream output;
    //open the file
    output.open("Times.dat");
    //declare and initialize variables
    const int TOTCHNS1=12;//total chance of the level 1 and 2
    const int TOTCHNS2=18;//total chance of the level 3
    const int SIZE1=4;//smaller size
    const int SIZE2=6;//larger size
    int size;
    string dash;
    string answer;
    int level;
    int tyTime=0;  //how many tyTime user tried
    int gusCorr=0;//how many correct number have been guessed 
    int chnsLft;  //chance counter(how many chances left)
    int hin=0;//count how many times player use hint
    int digit=0;  //digit of the user guesses
    char guess=0; //the number user guesses
    char pswd[SIZE2]={};//the password store in the array
    vector<int> inputDg;//the digits finished
    
    //introduce the game
    introduce();
    do {
        cout<<endl<<"*****************LEVEL SELECTION*****************"<<endl;
        cout<<"    1.Easy:"<<endl;
        cout<<"      Feature: (1)4 digit"<<endl;
        cout<<"               (2)No Repeat Number"<<endl;
        cout<<"               (3)Including sample input"<<endl;
        cout<<"    2.Normal:"<<endl;
        cout<<"      Feature: (1)4 digit"<<endl;
        cout<<"               (2)Might has repeat number"<<endl;
        cout<<"               (3)Including a hint for a digit"<<endl;
        cout<<"    3.Hard"<<endl;
        cout<<"      Feature: (1)6-digit"<<endl;
        cout<<"               (2)Might has repeat number"<<endl;
        cout<<"               (3)Including a hint for a digit"<<endl;
        cout<<"Please choose a level(Type 1,2,or 3)"<<endl;
        cin>>level;
        if(level<1||level>3) 
            cout<<"Invalid Input"<<endl;
    }while(level<1||level>3);
    //After choosing level, set the size of pswd and chances left
    if(level==1||level==2) {
        size=SIZE1;
        chnsLft=TOTCHNS1;
    } else {
        size=SIZE2;
        chnsLft=TOTCHNS2;
    }
    //get a random password and put it in array
    gtPswd(pswd,level,SIZE1,SIZE2);
    //Use for loop get the password into strings
    for(int i=0;i<size;i++) {
        answer+=pswd[i];
    }
    dash=toDash(size);//get the dash
    
    //game begins
    while(chnsLft>0&&gusCorr<size) {    
        //Prompt user for the guess
        cout<<endl;
        cout<<"The password now looks like this: "<<dash<<endl;//Output dash
        cout<<"You have "<<chnsLft<<" chances left"<<endl;//output chances left
        ask(guess,digit,size,level,inputDg,pswd,hin);//Prompt user for guess
        char result=check(guess,digit,pswd,size);//check the guess
        switch(result) {
            case'1': { //if the number and place both are correct
                if(inside(inputDg,digit)) { //if user have finished that digit
                    cout<<"You already finish this digit,"
                        <<"try other digits"<<endl;
                } else {//user didn't finish this digit
                    replace(dash,guess,digit);//replace of the correct digit
                    inputDg.push_back(digit-1);//record the digit which has been finished to vector
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
        tyTime++;//keep track of how many tyTime user have input
    }
    if(chnsLft==0) { //No chances left for player
        cout<<"You lost"<<endl;
        output<<"You lost"<<endl;
    }
    if(gusCorr==size) { //when 4 digits have been guessed correctly
        output<<"You win this game after "<<tyTime<<" tries"<<endl;
        cout<<"You win this game after "<<tyTime<<" tries"<<endl;
    }
    cout<<"The answer is "<<answer<<endl;
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
    cout<<"****************** Welcome to Bomb password *******************"<<endl;
    cout<<"*     In this game, you should guess the 4-digit password     *"<<endl;
    cout<<"*         First, you will input a number that you guess       *"<<endl;
    cout<<"*         Then, you will input the digit of this number       *"<<endl;
    cout<<"*    The digit of the number from left to right is 1,2,3...   *"<<endl;
    cout<<"*      After you input these two information,the computer     *"<<endl;
    cout<<"*    will tell you whether the number and digit are correct   *"<<endl;
    cout<<"* If your guess is correct, your chances left won't count down*"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<<"Press Enter to start the game";
    cin.ignore();
}

void ask(char& guess,int& digit,int size,int level,vector <int>ipDg,char pswd[],int &hin) {
    do {
        cout<<"Please input a number you guess"<<endl;
        if(level==1)
            cout<<"If you need sample for input, type \'s\'"<<endl;
        if((level==2||level==3)&&hin<1)
            cout<<"If you need hint for answer, type \'i\'"<<endl;
        cin>>guess;
        cin.ignore();
        if((guess=='s'||guess=='S')&&level==1) { //when player need sample
            sample();//output sample via ifstream
        } else if((guess=='i'||guess=='I')&&(level==2||level==3)&&hin<1) { 
            //when player needs hint
            //limit only 1 hint player can get
            hint(ipDg,pswd,size);//display the hint
            hin++;
        } else if(guess<48||guess>57) {
            cout<<"Invalid input"<<endl<<endl;
        }
    } while(guess<48||guess>57);
    do {
        cout<<"Please input the digit of this number"<<endl;
        cin>>digit;
        cin.ignore();
        if(digit<1||digit>size)
            cout<<"Invalid input"<<endl<<endl;
    } while(digit<1||digit>size);
}

char check(char guess,int digit,const char pswd[],int size) {
    //Because array counts from 0,but digit from left to right is 1,2,3,4,so it need digit-1 for array
    if(guess==pswd[digit-1]) { //when guess and digit are correct
        return '1';
    } else if(indexOf(guess,pswd,size)) { //number is right but digit is wrong
        return '2';
    } else { //both are wrong
        return '3';
    }
}
//return whether the char is in the array
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
//return whether is digit has been finished
bool inside(const vector<int> inputDg,int digit) {
    bool temp=false;
    for(int i=0;i<inputDg.size();i++) {
        if(inputDg[i]==(digit-1))
            temp=true;
    }
    return temp;
}
//display sample via file
void sample() {
    string str;
    ifstream input;
    input.open("Sample.dat");
    while(input>>str) {
        if(str=="Now"||str=="If"||str=="You"||str=="<"||str=="Then,")
            cout<<endl;
        cout<<str<<' ';
    }
    cout<<endl<<endl;
    input.close();
}
//randomly generate the password
void gtPswd(char pswd[],int level,const int SIZE1,const int SIZE2){
    bool diff=true;
    if(level==1) {
        for(int i=0;i<SIZE1;i++) {
            char temp;
            do {
                diff=true;
                temp=rand()%10+'0';
                for(int j=0;j<i;j++) {
                if(temp==pswd[j]) diff=false;
                }
            }while(diff==false);
            pswd[i]=temp;
        }
    } else if(level==2) {
        for(int i=0;i<SIZE1;i++) {
            pswd[i]=rand()%10+'0';
        }
    } else {
        for(int i=0;i<SIZE2;i++) {
            pswd[i]=rand()%10+'0';
        }
    }
}
//Display the hint for player
void hint(vector<int> ipDg,char pswd[],int size) {
    int temp=0;
    int tip=0;
    bool done=false;//determine whether this digit has been done
    if(ipDg.size()!=0) { //when player already finish some digits
        do {
            done=false;
            temp=rand()%size;
            for(int i=0;i<ipDg.size();i++) {
                if(temp==ipDg[i]) done=true;
            }
        }while(done);
    } else { //when player didn't finish any digits
        temp=rand()%size;
    }
    //change the tip from char to integer
    tip=static_cast<int>(pswd[temp]-48);
    //Display the hint in binary form
    cout<<"Digit "<<(temp+1)<< " in binary is "<<bin(tip)<<endl;
}
//change the decimal to binary
int bin(int a) {
    int rm;//remainder
    int rs;//result
    int temp=1;
    vector<int> ary;//to store each digit of binary number
    while(a>0) {
        rm=a%2;
        a/=2;
        ary.push_back(rm);
    }
    for(int i=0;i<ary.size();i++) {
        rs+=temp*ary[i];
        temp*=10;
    }
    return rs;
}