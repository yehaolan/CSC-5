/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 7:43 PM
 * Purpose: Homework assignment(Gaddis_7thEd_Chap3_ProgChal22)
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    string name, //name
            age, //age
            city,//city
            col, //college
            pofs,//profession
            animl,//animal
            petNm;//A pet's name
    //Prompt user for some information
    cout << "Your name: ";
    getline(cin,name);
    cout << "Your age: ";
    getline(cin,age);
    cout << "The city you live: ";
    getline(cin,city);
    cout << "The college where you are studying: ";
    getline(cin,col);
    cout << "Your favorite profession: ";
    getline(cin,pofs);
    cout << "The animal you have: ";
    getline(cin,animl);
    cout << "The pet's name: ";
    getline(cin,petNm);
    
    //output a story
    cout << "There once was a person named " << name << " who lived in " << city << ".\n";
    cout << "At the age of " << age << ", " << name << " went to "<< col << ". "<< name << " graduated\n";
    cout   << "and went to work as a" << pofs << ". Then, " << name << endl;
    cout << "adopted a " << animl << " named " << petNm << ". They both lived happily ever after!\n";
    //Exit stage here
    return 0;
}

