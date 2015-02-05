/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 4, 2015, 10:58 AM
 */

#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const int COL=30;

//Function Prototypes
void filAray(char[][COL],int ROW,char);
void prntAry(char[][COL],int);
void inject(char[][COL],int,int,char);
void pause(int);
void gnrashn(char[][COL],int,char,char);
int cntNbor(char[][COL],int,char,int,int);
//Execution begins here
int main(int argc, char** argv) {
    const int ROW=10;
    int nGen=10;
    //declare 2d char array
    char array[ROW][COL];
    //Fill the array
    filAray(array,ROW,'*');
    //Inject the glider
    inject(array,4,13,'X');
    //print the array without glider
    prntAry(array,ROW);
    //Game of life for generation stipulate
    for(int gen=0;gen<nGen;gen++) {
        gnrashn(array,ROW,'*','X');
        pause(5);
    }
    return 0;
}

void pause(int secs) {
    //start the timer
    int end;
    int strt=static_cast<unsigned int>(time(0));
    do {
        end=static_cast<unsigned int>(time(0));
    }while(secs>(end-strt));
}


void inject(char a[][COL],int pRow,int pCol,char c) {
    a[pRow+0][pCol+1]=c;
    a[pRow+1][pCol+2]=c;
    a[pRow+2][pCol+0]=c;
    a[pRow+2][pCol+1]=c;
    a[pRow+2][pCol+2]=c;
}

void filAray(char a[][COL],int ROW,char d) {
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL;c++) {
            a[r][c]=d;
        }
    }
}
void prntAry(char a[][COL],int ROW) {
    cout<<endl;
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL;c++) {
            cout<<a[r][c];
        }
        cout<<endl;
    }
}

void gnrashn(char a[][COL],int ROW,char d,char nd) {
    for(int r=1;r<ROW-1;r++) {
        for(int c=1;c<COL-1;c++) {
            int nBr=cntNbor(a,ROW,d,r,c);
            if(a[r][c]!=d&&nBr<=1) a[r][c]=d;
            if(a[r][c]!=d&&nBr>=4) a[r][c]=d;
            if(a[r][c]==d&&nBr==3) a[r][c]=nd;
        }
    }
}

int cntNbor(char a[][COL],int ROW,char d,int r,int c) {
    //Count your neighbors
    int count=0;
    //3 TOP
    if(a[r-1][c-1]!=d)  count++;
    if(a[r-1][c]!=d)  count++;
    if(a[r-1][c+1]!=d)  count++;
    //2 MID
    if(a[r][c-1]!=d)  count++;
    if(a[r][c+1]!=d)  count++;
    //3 BOTTOM
    if(a[r+1][c-1]!=d)  count++;
    if(a[r+1][c]!=d)  count++;
    if(a[r+1][c+1]!=d)  count++;
    return count;
}