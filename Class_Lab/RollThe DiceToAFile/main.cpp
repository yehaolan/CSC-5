/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 12, 2015, 10:06 AM
 * Purpose: Illustrate file i/o and random number
 */

//System Libraries
#include <cstdlib> //Random rand(),srand()
#include <iostream> //Keyboard/monitor I/O
#include <fstream> //File I/O
#include <ctime> //Time Functions
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //declare a file object
    ofstream output;
    //open the file
    output.open("RollTheDice.dat");
    //declare 5 dice
    unsigned short die1,die2,die3,die4,die5;
    //set the value for each dice
    die1 = rand()%6+1;
    die2 = rand()%6+1;
    die3 = rand()%6+1;
    die4 = rand()%6+1;
    die5 = rand()%6+1;
    //Output the result to the screen
    cout << "Yahtzee first roll => ";
    cout << die1 << " " << die2 << " " << die3;
    cout << " " << die4 << " "<< die5 << endl;
    //output the result to a file
    output << "Yahtzee first roll => ";
    output << die1 << " " << die2 << " " << die3;
    output << " " << die4 << " "<< die5 << endl;
    //Close stream
    output.close();
    return 0;
}

