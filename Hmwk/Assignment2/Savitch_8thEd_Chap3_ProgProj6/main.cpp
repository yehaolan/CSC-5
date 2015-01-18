/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 17, 2015, 3:34 PM
 * Purpose: Homework assignment2(Savitch_8thEd_Chap3_ProgProj6)
 */


//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short a,//Quadratic Term
          b,//First Term
          c;//constant term
    float dscrmnt;//discriminant
    float root;
    char ans;
    //introduce program
    cout << "This program solves quadratic equation to finds its boots" << endl;
    cout << "The quadratic equation likes ax^2+bx+c=0(a not equal to 0)" << endl;
    do {
        //prompt user for a,b,c these three number
        cout << "Please input the number of a,b,c" << endl;
        cout << "Quadratic term a cannot be zero" << endl;
        //Limit a cannot be 0
        do {
            cin >> a >> b >> c;
            if(a==0) {
                cout << "a cannot be zero" << endl;
                cout << "Input a,b,c one more time" <<endl;
            }
        } while(a==0);
        //display the quadratic equation
        cout << "The quadratic equation looks like ";
        cout <<a<<"x^2" <<(b<0?"":"+")<<b<<"x"<<(c<0?"":"+")<<c<<"=0"<<endl;
        //calculate the discriminant
        dscrmnt = b*b-4*a*c;
        //determine how many roots quadratic equation has and calculate the root(s)
        if(dscrmnt<0) {
            //no real root
            cout << "This quadratic equation doesn't have real root" << endl;
        } else if(dscrmnt==0) {
            //when discriminant equals to 0, quadratic equation has a single root
            cout << "This quadratic equation has a single real root" << endl;
            //calculate the root
            root = 0.5f*(-b)/a;
            //Output the root
            cout << "The single real root is " << root << endl;
        } else {
           //when discriminant greater to 0, quadratic equation has two real roots 
           cout << "This quadratic equation has two real roots" << endl;
           //calculate first root and output first root
           root = 0.5f*(-b+sqrt(dscrmnt))/a;
           cout << "The root 1 is " << root << endl;
           //calculate second root and output second root
           root = 0.5f*(-b-sqrt(dscrmnt))/a;
           cout << "The root 2 is " << root << endl;
        }
        cout << "Would you like to run the program again? 'Y' for yes,'N' for no."<< endl;
        cin >> ans;
    } while(ans=='y'||ans=='Y');
    //Exit stage right
    return 0;
}

