/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 6, 2015, 7:31 AM
 * Purpose:Savitch_8thEd_Chap7_ProgProj7
 */

//System libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Libraries
void input(char [],int);//Prompt user for numbers
void chToInt(const char [],int,int []);//change char array to int array
void reverse(int [],const int);//reverse the array
void add(int [],const int [],int,const int [],int);//add two numbers and put it to new array]

//execution begins here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=25;
    char ipch1[SIZE]={};//FIRST Input from user(char array)
    char ipch2[SIZE]={};//SECOND Input from user(char array)
    int ip1[SIZE]={};//FIRST Input from user(int array)
    int ip2[SIZE]={};//SECOND Input from user(int array)
    int rs[SIZE]={};//the result of the addition
    //Prompt user for 2 numbers and store it into char array
    input(ipch1,1);
    input(ipch2,2);
    //store the number to integer array
    chToInt(ipch1,strlen(ipch1),ip1);
    chToInt(ipch2,strlen(ipch2),ip2);
    cout<<endl;
    //Reverse the array
    reverse(ip1,strlen(ipch1));
    reverse(ip2,strlen(ipch2));
    //add two numbers from array and store into another array
    add(rs,ip1,strlen(ipch1),ip2,strlen(ipch2));
    reverse(rs,SIZE);//reverse the result
    //output the result of addition
    if(rs[4]!=0) { //when rs[5]!=0, digit of result greater than 20
        cout<<"Your result is overflow"<<endl;
    } else { 
        for(int i=0;i<strlen(ipch1);i++) {
            cout<<ipch1[i];
        }
        cout<<"+";
        for(int i=0;i<strlen(ipch2);i++) {
            cout<<ipch2[i];
        }
        cout<<"=";
        bool zero=false;
        for(int i=0;i<SIZE;i++) {
            cout<<"";
            if(rs[i]!=0) zero=true;
            if(zero) cout<<rs[i];
        }
    }   
    //Exit stage right
    return 0;
}
void input(char ip[],int x) {
    bool digit;
    do {
        cout<<"Input number "<<x<<": ";
        cin>>ip;
        digit=true;
        for(int i=0;i<strlen(ip);i++) {
            if(!isdigit(ip[i])) digit=false;
        }
        if(!digit||strlen(ip)>20)
            cout<<"Please input the number less than 20-digit"<<endl;
    }while(!digit||strlen(ip)>20);
}
//change char array to int array
void chToInt(const char ch[],int SIZE,int a[]) {
    for(int i=0;i<SIZE;i++) {
        a[i]=static_cast<int>(ch[i]-48);
    }
}

void reverse(int ip[],const int n) {
    int rv[n];//declare a temp array
    //assign the inverted original array to temp array
    for(int i=1;i<=n;i++) {
        rv[i-1]=ip[n-i];
    }
    //assign the temp array to original array
    for(int i=0;i<n;i++) {
        ip[i]=rv[i];
    }
}
void add(int rs[],const int ip1[],int n1,const int ip2[],int n2) {
    int n=(n1>=n2?n1:n2);
    //add digit by digit,when one digit over 9,this digit minus 10,next digit+1
    for(int i=0;i<n;i++) {
        rs[i]=rs[i]+ip1[i]+ip2[i];
        if(rs[i]>=10) {
            rs[i]-=10;
            rs[i+1]+=1;
        }
    }
}