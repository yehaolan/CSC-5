/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 29, 2015, 9:16 AM
 * Purpose:Utilizing partially filled array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User Libraries

//Global Constants
const int COL=200;

//Function Prototypes
void filAray(int [],int);
void filAray(vector<int> &,int);
void filAray(int [][COL],int,int);
void prntAry(const int [],int,int);
void prntAry(const vector<int> &,int,int);
void prntAry(const int [][COL],int,int);

//Execution begins here
int main(int argc, char** argv) {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    //declare variables and arrays
    const int ROW=200;
    int pFilCol=10,pFilRow=5,perLine=5;
    int array[COL]={};
    int array2D[COL][ROW]={};
    vector<int> varray(COL,0);
    //fill the array,vector,2D array
    filAray(array,pFilCol);
    filAray(varray,pFilCol);
    filAray(array2D,pFilRow,pFilCol);
    //print the array,vector,2D array
    prntAry(array,pFilCol,perLine);
    prntAry(varray,pFilCol,perLine);
    prntAry(array2D,pFilRow,pFilCol);
    //Exit stage right
    return 0;
}

//Random fill the array with 2-digit number
void filAray(int a[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}

//Random fill the vector with 2-digit number
void filAray(vector<int> &a,int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}

//Random fill 2d array
void filAray(int a[][COL],int r,int c) {
    for(int row=0;row<r;row++) {
        for(int col=0;col<c;col++) {
            a[row][col]=rand()%90+10;
        }
    }
}

//print perLine col for the array output by row
void prntAry(const int a[],int n,int perLine) {
    cout<<endl<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}

//print perLine col for the vector output by row
void prntAry(const vector<int> &a,int n,int perLine) {
    cout<<endl<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}



//Randomly print 2d array
void prntAry(const int a[][COL],int r,int c) {
    cout<<endl<<endl;
    for(int row=0;row<r;row++) {
        for(int col=0;col<c;col++) {
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
}