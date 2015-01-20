/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on January 15, 2015, 10:27 AM
 * Purpose:Homework assignment(Gaddis_7thEd_Chap4_ProgChal5)
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
    short weight,
          height;
    float BMI;
    //Prompt user for weight and height
    do {
        cout << "Please input your weight(pounds)" << endl;
        cout << "Please input a positive number" << endl;
        cin >> weight;
    }while(weight<=0);
    
    do {
        cout << "Please input your height(inches)" << endl;
        cout << "Please input a positive number" << endl;
        cin >> height;
    }while(height<=0);
    //calculate the BMI
    BMI = static_cast<float>(weight)*703/height/height;
    //determine the BMI level
    if(BMI>=18.5&&BMI<=25)
        cout << "Congratulation! Your weight is optimal." << endl;
    if(BMI<18.5)
        cout << "Sorry! You are considered to be underweight." << endl;
    if(BMI>25)
        cout << "Sorry! You are considered to be overweight." << endl;
    //Exit stage right
    return 0;
}

