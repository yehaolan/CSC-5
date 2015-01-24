/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 24, 2015, 10:26 AM
 * Purpose: Homework assignment5 (Savitch_8thEd_Chap5_ProgProj13)
 * Area and perimeter of triangle
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void calRst(short,short,short,short&,float&);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    short a,b,c;//the length of three sides of triangle
    short prmt;//perimeter of triangle
    float area;//area of triangle
    //Prompt user for three sides of triangles
    do {
        cout<<"Input the length of three sides of triangle(integer)"<<endl;
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a)
            cout<<"This is not triangle! Please input again"<<endl<<endl;
    } while(a+b<=c||a+c<=b||b+c<=a);
    
    calRst(a,b,c,prmt,area);
    return 0;
}

void calRst(short a,short b,short c,short& prmt,float& area) {
    //declare variables
    float s;//half of perimeter of triangle
    prmt=a+b+c;
    s=prmt/2.0f;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<setprecision(2)<<fixed;
    cout<<"The perimeter of the triangle is "<<prmt<<endl;
    cout<<"The area of the triangle is "<<area<<endl;
}