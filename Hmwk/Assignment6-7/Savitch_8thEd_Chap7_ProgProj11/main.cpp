/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 4, 2015, 8:43 PM
 * Purpose:Savitch_8thEd_Chap7_ProgProj11
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global constants
const int COL=4;
//Function prototypes
void filAray(char[][COL],int);

//Execution Begins here
int main(int argc, char** argv) {
    const int ROW=7;
    char sit[ROW][COL]={};
    filAray(sit,ROW);
    for(int i=0;i<ROW;i++) {
        cout<<(i+1)<<" ";
        for(int j=0;j<COL;j++) {
            cout<<sit[i][j]<<" ";
        }
        cout<<endl;
    }
    //Exit stage right
    return 0;
}

void filAray(char a[][COL],int ROW) {
    for(int i=0;i<COL;i++) {
        for(int j=0;j<ROW;j++) {
            if(i==0) a[j][i]='A';
            if(i==1) a[j][i]='B';
            if(i==2) a[j][i]='C';
            if(i==3) a[j][i]='D';
        }
    }
}