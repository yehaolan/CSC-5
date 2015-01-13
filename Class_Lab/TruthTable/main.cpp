/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 13, 2015, 9:15 AM
 * Purpose: 
 */

//System Libraries
#include <iostream>
using namespace std;

//User libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //declare 2 boolean variables
    bool X,Y;
    //Output the heading
    cout << "X Y !X !Y  X&&Y X||Y X^Y X^Y^Y ";
    cout << "X^Y^X !(X||Y) !X&&!Y !(X&&Y) !X||!Y" << endl;
    //Fill in the first row
    X = true; Y = true;
    cout <<(X?'T':'F')<<" ";
    cout <<(Y?'T':'F')<<"  ";
    cout <<(!X?'T':'F')<<"  ";
    cout <<(!Y?'T':'F')<<"    ";
    cout <<(X&&Y?'T':'F')<<"    ";
    cout <<(X||Y?'T':'F')<<"   ";
    cout <<(X^Y?'T':'F')<<"    ";
    cout <<(X^Y^Y?'T':'F')<<"    ";
    cout <<(X^Y^X?'T':'F')<<"       ";
    cout <<(!(X||Y)?'T':'F')<<"      ";
    cout <<(!X&&!Y?'T':'F')<<"      ";
    cout <<(!(X&&Y)?'T':'F')<<"       ";
    cout <<(!X||!Y?'T':'F')<<"    ";
    cout << endl;
    //Fill in the second row
    Y = false;
   cout <<(X?'T':'F')<<" ";
    cout <<(Y?'T':'F')<<"  ";
    cout <<(!X?'T':'F')<<"  ";
    cout <<(!Y?'T':'F')<<"    ";
    cout <<(X&&Y?'T':'F')<<"    ";
    cout <<(X||Y?'T':'F')<<"   ";
    cout <<(X^Y?'T':'F')<<"    ";
    cout <<(X^Y^Y?'T':'F')<<"    ";
    cout <<(X^Y^X?'T':'F')<<"       ";
    cout <<(!(X||Y)?'T':'F')<<"      ";
    cout <<(!X&&!Y?'T':'F')<<"      ";
    cout <<(!(X&&Y)?'T':'F')<<"       ";
    cout <<(!X||!Y?'T':'F')<<"    ";
    cout << endl;
    //Fill in third row
    X=false;Y=true;
    cout <<(X?'T':'F')<<" ";
    cout <<(Y?'T':'F')<<"  ";
    cout <<(!X?'T':'F')<<"  ";
    cout <<(!Y?'T':'F')<<"    ";
    cout <<(X&&Y?'T':'F')<<"    ";
    cout <<(X||Y?'T':'F')<<"   ";
    cout <<(X^Y?'T':'F')<<"    ";
    cout <<(X^Y^Y?'T':'F')<<"    ";
    cout <<(X^Y^X?'T':'F')<<"       ";
    cout <<(!(X||Y)?'T':'F')<<"      ";
    cout <<(!X&&!Y?'T':'F')<<"      ";
    cout <<(!(X&&Y)?'T':'F')<<"       ";
    cout <<(!X||!Y?'T':'F')<<"    ";
    cout << endl;
    //Fill in fourth row
    Y=false;
    cout <<(X?'T':'F')<<" ";
    cout <<(Y?'T':'F')<<"  ";
    cout <<(!X?'T':'F')<<"  ";
    cout <<(!Y?'T':'F')<<"    ";
    cout <<(X&&Y?'T':'F')<<"    ";
    cout <<(X||Y?'T':'F')<<"   ";
    cout <<(X^Y?'T':'F')<<"    ";
    cout <<(X^Y^Y?'T':'F')<<"    ";
    cout <<(X^Y^X?'T':'F')<<"       ";
    cout <<(!(X||Y)?'T':'F')<<"      ";
    cout <<(!X&&!Y?'T':'F')<<"      ";
    cout <<(!(X&&Y)?'T':'F')<<"       ";
    cout <<(!X||!Y?'T':'F')<<"    ";
    cout << endl;
    //Exit stage right
    return 0;
}

