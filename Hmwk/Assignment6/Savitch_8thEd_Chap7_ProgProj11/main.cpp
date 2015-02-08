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
void prtAray(char[][COL],int);
void assign(const char [],char[][COL],int);

//Execution Begins here
int main(int argc, char** argv) {
    //declare variables
    const int ROW=7;
    const int CHNUM=3;//limit the char of user input
    char sit[ROW][COL]={};
    char select[CHNUM];
    filAray(sit,ROW);//fill the sit in order
    do {
        prtAray(sit,ROW);//print out the sit
        do {
            cout<<"Which seat you would like to choose?(For example: 4A.)"<<endl;
            cout<<"Note:Input one seat at one time.Please input capital letter!"<<endl;
            cout<<"Enter 0 to exit the program"<<endl;
            cin>>select;
            if(select[0]<48||select[0]>55||select[1]<65||select[1]>68)
                cout<<"Invalid input"<<endl;
        }while(select[0]<48||select[0]>55);
        assign(select,sit,ROW);
    }while(select[0]!='0');
    //Exit stage right
    return 0;
}

void assign(const char sl[],char sit[][COL],int ROW) {
    int r=static_cast<int>(sl[0]-49);
    int c=static_cast<int>(sl[1]-65);
    if(sit[r][c]!='X')
        sit[r][c]='X';
    else
        cout<<"Sorry,this seat is occupied,please select other seats"<<endl;
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

void prtAray(char a[][COL],int ROW) {
    cout<<endl;
    cout<<"The seat of airplane looks like that(X means it is occupied):"<<endl;
    for(int i=0;i<ROW;i++) {
        cout<<" "<<(i+1)<<" ";
        for(int j=0;j<COL;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}