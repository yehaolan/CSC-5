/* 
 * File:   main.cpp
 * Author: Haolan Ye
 * Created on February 7, 2015, 8:03 AM
 * Purpose:Baby name
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void read(string [],string [],int[],int);
//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=1000;
    string boys[SIZE]={};
    string girls[SIZE]={};
    int rank[SIZE]={};
    read(boys,girls,rank,SIZE);
    
    //Exit stage right
    return 0;
}

void read(string boys[],string girls[],int rank[],int SIZE) {
    int num;
    string bn;
    string gn;
    ifstream input;
    input.close();
    input.open("babynames2004.dat");
    for(int i=0;i<SIZE;i++) {
        input>>rank[i];
        input>>boys[i];
        input>>girls[i];
    }
    
    for(int i=0;i<SIZE;i++) {
        cout<<rank[i]<<" "<<boys[i]<<" "<<girls[i]<<endl;
    }
    
    input.close();
}