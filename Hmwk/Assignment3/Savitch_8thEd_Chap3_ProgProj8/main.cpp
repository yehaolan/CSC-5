/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 17, 2015, 9:55 PM
 * Purpose: Homework assignment2(Savitch_8thEd_Chap3_ProgProj8)
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables and initialize 
    char crd;      //the kind of the card
    short crdPtB;  //the bigger point of card
    short crdPtS;  //the smaller point of card
    short valueB=0;  //the bigger total value(ace count 11)
    short valueS=0;  //the smaller total value(ace count 1)
    short crdNum;  //the number of cards user has
    
    //introduce program and prompt user for the number of cards he has
    cout << "This program scores a blackjack hand" << endl;
    do {
        cout << "How many cards you have?(an integer between 2 and 5)";
        cin >> crdNum;
        if(crdNum<2||crdNum>5)
            cout << "The range is from 2 to 5" << endl;
    } while(crdNum<2||crdNum>5);
    //introduce how to input the card
    cout << "When you input the card from ace,2,...,queen,king" << endl;
    cout << "You should input a,2,3,4,5,6,7,8,9,t,j,q, or k" << endl;
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    //use a loop to ask user for card and calculate the value
    for(int i=1;i<=crdNum;i++) {
        crdPtB=0;
        crdPtS=0;
        cout<<"Input the card"<<i<<": ";
        cin>>crd;
        //card 2-9
        if(crd>=50&&crd<=57) {
            crdPtB=static_cast<short>(crd)-48;
            crdPtS=static_cast<short>(crd)-48;
        } else if(crd=='t'||crd=='j'||crd=='q'||crd=='k'||crd=='T'||crd=='J'||crd=='Q'||crd=='K'){
            //card 10,jack,queen,king
            crdPtB=10;
            crdPtS=10;
        } else if(crd=='a'||crd=='A') {
            //card ace
            crdPtB=11;
            crdPtS=1;
        } else {
            //other card is invalid
            cout<<"You have input the invalid card"<<endl;
            cout<<"Please input again"<<endl;
            i--;
        } 
        valueB+=crdPtB;
        valueS+=crdPtS;
    }
    //when the smaller total value greater than 21, means busted
    if(valueB>21&&valueS>21) {
        cout<<"Busted"<<endl;
    } else if(valueB>21&&valueS<=21) {
        //the bigger total value greater than 21,but smaller value not,get the smaller one
        cout<<"You get "<<valueS<<endl;
    } else {
        //bigger and smaller total value both less than 21,get the bigger one
        cout<<"You get "<<valueB<<endl;
    }
    
    //Exit stage here
    return 0;
}

