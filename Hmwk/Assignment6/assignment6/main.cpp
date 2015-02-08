/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 8, 2015, 10:03 AM
 * Purpose: Homework assignment 6(including 7 Savitch problems
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global constants
const int COL=4;
const int COL1=30;

//Function prototypes
void pg1();//Savitch_8thEd_Chap7_ProgProj4
void pg2();//Savitch_8thEd_Chap7_ProgProj5
void pg3();//Savitch_8thEd_Chap7_ProgProj6
void pg4();
void pg5();
void pg6();
void pg7();
float calSD(const float[],int);
void dspOcur(int[],int);
void bubSort(int [],int);
void fndOcur(int[],int[],int[],int);
void filAray(int [],int);
void swap(int &,int &);
void prntAry(const int [],int,int);
void insrSrt(const int [],int [],int);
void input(char [],int);//Prompt user for numbers
void chToInt(const char [],int,int []);//change char array to int array
void reverse(int [],const int);//reverse the array
void add(int [],const int [],int,const int [],int);//add two numbers and put it to new array
void getOcc(const char [],char [],const int,int &);//get occurred letters
void gtTimes(const char [],const int,int [],const char [],int);//get the number of occurrence of letter
void sort(char [],int,int []);//sort two array at a time
void filAray(char[][COL],int);
void prtAray(char[][COL],int);
void assign(const char [],char[][COL],int);
void filAry(char[][COL1],int,char);
void pntAry(char[][COL1],int);
void prntMap(char [][COL1],int,char);
void inject(char[][COL1],int,int,char);
void pause(int);
void gnrashn(char[][COL1],char[][COL1],int,char,char);
int cntNbor(char[][COL1],int,char,int,int);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    int ans;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.Standard Deviation"<<endl;
        cout<<"2.Number Entries"<<endl;
        cout<<"3.Insertion Sort"<<endl;
        cout<<"4.Addition"<<endl;
        cout<<"5.Letter Occurrence"<<endl;
        cout<<"6.Seat Selection"<<endl;
        cout<<"7.Game of Life"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        do {
            cout<<"Please select the program(0 to 7)"<<endl;
            cin>>ans;
            if(ans<0||ans>7)
                cout<<"Invalid input"<<endl;
        }while(ans<0||ans>7);

        switch(ans) {
            case 1: pg1(); break;
            case 2: pg2(); break;
            case 3: pg3(); break;
            case 4: pg4(); break;
            case 5: pg5(); break;
            case 6: pg6(); break;
            case 7: pg7(); break;
            case 0: {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            default:;
        }
        if(ans!=0) {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
            cin.ignore();
        }
    }while(ans!=0);
    
    //Exit stage
    return 0;
}

void pg1() {
    //Savitch_8thEd_Chap7_ProgProj4
    //declare variables
    const int SIZE=100; //the size of array
    float array[SIZE];  
    int num;//the number of number user wants to input
    float sd;//standard deviation
    //Prompt user for number of inputs
    cout<<"Input the number of inputs you would"<<endl;
    cout<<"like to calculate standard deviation"<<endl;
    cout<<"Note: An positive integer less than 100"<<endl;
    cin>>num;
    //Prompt user for input the elements of array
    cout<<"Please fill the array"<<endl;
    for(int i=0;i<num;i++) {
        cout<<(i+1)<<": ";
        cin>>array[i];
    }
    sd=calSD(array,num);
    cout<<"The standard deviation of these number is "<<sd<<endl;
}

void pg2() {
    //Savitch_8thEd_Chap7_ProgProj5
    //declare variables
    int choice;
    do {
        cout<<"Which way you prefer to read a list of integer?"<<endl;
        cout<<"1. File"<<endl;
        cout<<"2. Keyboard"<<endl;
        cin>>choice;
        if(choice<1||choice>2)
            cout<<"Invalid input"<<endl;
    } while(choice<1||choice>2);
    
    if(choice==1){ //if choose file
        //set seed for random number
        srand(static_cast<unsigned int>(time(0)));
        //declare variables
        const int SIZE=20;
        char name[30];//char array for file name
        int num;
        int array[SIZE]={};
        //file object
        ofstream output;
        ifstream input;
        //get file name
        cout<<"Input the name of file you would like to open(including suffix)"<<endl;
        cin>>name;
        output.open(name);
        //randomly output the number to the file
        for(int i=0;i<SIZE;i++) {
            output<<rand()%15+1<<endl;
        }
        output.close();
        input.open(name);
        //copy the number to the array
        for(int i=0;input>>num;i++) {
            array[i]=num;
        }
        dspOcur(array,SIZE);//display the number of occurrences of inputted number
        input.close();
    } else {    //choose keyboard
        const int SIZE=20;
        int array[SIZE];
        //Prompt user for 20 integer
        cout<<"Please input 20 integer to the array"<<endl;
        for(int i=0;i<SIZE;i++) {
            cout<<(i+1)<<": ";
            cin>>array[i];
        }
        dspOcur(array,SIZE);//display the number of occurrences of inputted number
    }
}

void pg3() {
    //Savitch_8thEd_Chap7_ProgProj6
    //set the seed for random numbers
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int SIZE=100000;
    int pFilRow=100;
    int pl=10;//per line
    int array[SIZE]={};
    int rs[SIZE]={};//result of sorting
    //fill the array
    filAray(array,pFilRow);
    //print the array
    prntAry(array,pFilRow,pl);
    //insertion sort
    insrSrt(array,rs,pFilRow);
    //print the array
    prntAry(rs,pFilRow,pl);
}
void pg4() {
    //Savitch_8thEd_Chap7_ProgProj7
    //declare variables
    const int SIZE=25;
    char ipch1[SIZE]={};//FIRST Input from user(char array)
    char ipch2[SIZE]={};//SECOND Input from user(char array)
    int ip1[SIZE]={};//FIRST Input from user(int array)
    int ip2[SIZE]={};//SECOND Input from user(int array)
    int rs[SIZE]={};//the result of the addition
    //Prompt user for 2 numbers and store it into char array
    cout<<"This program calculates the addition of two numbers"<<endl;
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
}
void pg5() {
    //Savitch_8thEd_Chap7_ProgProj8
    //declare variables
    const int SIZE=100;
    char line[SIZE];//the sentence of input
    char occed[SIZE];//array of all occurred letter 
    int occTm[SIZE];//array of number of occurrence of letter
    int count=0;
    bool wro;//wrong
    //Introduce the program
    cout<<"This program can find out the number of "<<endl;
    cout<<"occurrence of letter in a sentence"<<endl;
    //Prompt user for a lowercase sentence with period ending
    do {
        wro=false;
        cout<<endl<<"Input a sentence which is ended with period"<<endl;
        cout<<"Note:Only lowercase letter can be accepted"<<endl;
        cin.getline(line,SIZE);
        for(int i=0;i<strlen(line)-1;i++) {
            if(line[i]==' ') wro=false;
            else if(line[i]<97||line[i]>122) wro=true;
        }
        if(line[0]==' ') wro=true;
        if(line[strlen(line)-1]!='.') wro=true;
    }while(wro);
    //get occurred letters
    getOcc(line,occed,strlen(line)-1,count);
    //get the number of occurrence of letter
    gtTimes(occed,count,occTm,line,strlen(line)-1);
    sort(occed,count,occTm);
    cout<<" Letter  "<<" Number of occurrence"<<endl;
    for(int i=0;i<count;i++) {
        cout<<"    "<<occed[i]<<"            "<<occTm[i]<<endl;
    }
}
void pg6() {
    //Savitch_8thEd_Chap7_ProgProj11
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
            if(select[0]=='0') {
                cout<<"This is the end of selection"<<endl;
            }else if(select[0]<49||select[0]>55||select[1]<65||select[1]>68) {
                cout<<"Invalid input"<<endl;
            }
        }while(select[0]<48||select[0]>55);
        assign(select,sit,ROW);
    }while(select[0]!='0');
}
void pg7() {
    //Savitch_8thEd_Chap7_ProgProj13
    const int ROW=10;
    int nGen=20;
    //declare 2d char array
    char array[ROW][COL1]={};
    char brray[ROW][COL1]={};
    //Fill the array
    filAry(array,ROW,'*');
    filAry(brray,ROW,'*');
    //print the array without glider
    pntAry(array,ROW);
    //Inject the glider
    inject(array,1,10,'X');
    //print the array with glider
    pntAry(array,ROW);
    pause(1);
    //Game of life for generation stipulated
    for(int gen=1;gen<=nGen;gen++) {
        cout<<"Gen "<<gen<<endl;
        if(gen%2) {
            gnrashn(array,brray,ROW,'*','X');
            pntAry(brray,ROW);
        } else {
            gnrashn(brray,array,ROW,'*','X');
            pntAry(array,ROW);
        }
        pause(1);
    }
}

float calSD(const float a[],int n) {
    float ave=0;//average of all numbers
    float sd=0;//standard deviation
    float temp=0;
    for(int i=0;i<n;i++) {
        ave+=a[i];
    }
    ave/=n; //get the average of numbers
    //record calculation with temp
    for(int i=0;i<n;i++) {
        temp+=(a[i]-ave)*(a[i]-ave);
    }
    sd=sqrt(temp/n);
    return sd;
}

void dspOcur(int a[],int size) {
    const int SIZE=20;
    int occNum[SIZE]={};//the array storing the number occurred
    int fnd[SIZE]={};//record the number of occurrence
    int count=0;//count how many number occurred
    //get all numbers occur in the array
    for(int i=0;i<SIZE;i++) {
        bool inside=false;
        for(int j=0;j<SIZE;j++){
            if(a[i]==occNum[j]) inside=true;
        }
        if(!inside) occNum[count++]=a[i];
    }
    //display all element of array
    cout<<"These numbers are in the array:"<<endl;
    for(int i=0;i<SIZE;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //sort the occur number from big -> small
    bubSort(occNum,count); 
    cout<<endl;
    //find out the number of occurring of occur number
    fndOcur(occNum,fnd,a,count);
    //display the results
    cout<<"  N   "<<" Count "<<endl;
    for(int i=0;i<count;i++) {
        cout<<setw(3)<<occNum[i]<<setw(6)<<fnd[i]<<endl;
    }
    int totOcc=0;
    for(int i=0;i<count;i++){
        totOcc+=fnd[i];
    }
    if(totOcc!=20)
        cout<<setw(3)<<0<<setw(6)<<(20-totOcc)<<endl;
    
    cout<<endl;
}

void bubSort(int a[],int size) {
    bool swap;
    do {
        swap=false;
        for(int i=0;i<size-1;i++) {
            if(a[i]<a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

void fndOcur(int on[],int fnd[],int a[],int count) { //on[]means occur numbers
    const int SIZE=20;
    //record the number of occurring of occur number
    for(int i=0;i<count;i++) {
        int count=0;
        for(int j=0;j<SIZE;j++) {
            if(on[i]==a[j]) count++;
        }
        fnd[i]=count;
    }
}
//Randomly fill the array which makes it sorted
void filAray(int a[],int n) {
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
}
void swap(int &a,int &b) {
    //in place swap using logical exclusive or's
    a=a^b;
    b=a^b;
    a=a^b;
}
//print perLine col for the array output by row
void prntAry(const int a[],int n,int perLine) {
    cout<<endl<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}

void insrSrt(const int a[],int rs[],int n) {
    for(int i=0;i<n;i++) {
        rs[i]=a[i];
        for(int j=i;j>0;j--){
            if(rs[j]<rs[j-1]) swap(rs[j],rs[j-1]);
        }
    }
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
//find out all occurring letter
void getOcc(const char line[],char occ[],const int N,int &count) {
    bool repe;
    for(int i=0;i<N;i++) {
        repe=false;
        for(int j=0;j<i;j++){
            if(occ[j]==line[i]) repe=true;
            if(line[i]==' ') repe=true;
        }
        if(!repe) occ[count++]=line[i];
    }
}
//get how many times of all occurred letters occur
void gtTimes(const char occ[],const int n,int occTm[],const char line[],int len) {
    int count;
    for(int i=0;i<n;i++) {
        count=0;
        for(int j=0;j<len;j++) {
            if(occ[i]==line[j]) count++;
        }
        occTm[i]=count;
    }
}

//sort the array that store occur letters and array that store number of occurrence of these letter 
void sort(char occ[],int n,int occTm[]) {
    //mark sort
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(occTm[i]<occTm[j]) {
                int temp=occTm[i];
                occTm[i]=occTm[j];
                occTm[j]=temp;
                char tem=occ[i];
                occ[i]=occ[j];
                occ[j]=tem;
            }
        }
    }
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
void pause(int secs) {
    //start the timer
    int end;
    int strt=static_cast<unsigned int>(time(0));
    do {
        end=static_cast<unsigned int>(time(0));
    }while(secs>(end-strt));
}


void inject(char a[][COL1],int pRow,int pCol,char c) {
    a[pRow+0][pCol+1]=c;
    a[pRow+1][pCol+2]=c;
    a[pRow+2][pCol+0]=c;
    a[pRow+2][pCol+1]=c;
    a[pRow+2][pCol+2]=c;
}

void filAry(char a[][COL1],int ROW,char d) {
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL1;c++) {
            if(r==0) {
                a[r][c]=c%10+48;
            }else if(r==(ROW-1)) {
                a[r][c]=c%10+48;
            }else if(c==0){
                a[r][c]=c%10+48;
            }else if(c==(COL1-1)){
                a[r][c]=c%10+48;
            }else{
                a[r][c]=d;
            }
        }
    }
}
void pntAry(char a[][COL1],int ROW) {
    cout<<endl;
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL1;c++) {
            cout<<a[r][c];
        }
        cout<<endl;
    }
    cout<<endl;
}
void prntMap(char a[][COL1],int ROW,char nd) {
    cout<<endl;
    for(int r=1;r<ROW-1;r++) {
        cout<<" ";
        for(int c=1;c<COL1-1;c++) {
            int nBr=cntNbor(a,ROW,nd,r,c);
            cout<<nBr;
        }
        cout<<endl;
    }
}

void gnrashn(char a[][COL1],char b[][COL1],int ROW,char d,char nd) {
    for(int r=1;r<ROW-1;r++) {
        for(int c=1;c<COL1-1;c++) {
            int nBr=cntNbor(a,ROW,nd,r,c);
            if(a[r][c]==nd&&nBr<=1) b[r][c]=d;
            else if(a[r][c]==nd&&(nBr==2||nBr==3)) b[r][c]=nd;
            else if(a[r][c]==nd&&nBr>=4) b[r][c]=d;
            else if(a[r][c]==d&&nBr==3) b[r][c]=nd;
            else b[r][c]=a[r][c];
        }
    }
}

int cntNbor(char a[][COL1],int ROW,char d,int r,int c) {
    //Count your neighbors
    int count=0;
    //3 TOP
    if(a[r-1][c-1]==d)  count++;
    if(a[r-1][c]==d)  count++;
    if(a[r-1][c+1]==d)  count++;
    //2 MID
    if(a[r][c-1]==d)  count++;
    if(a[r][c+1]==d)  count++;
    //3 BOTTOM
    if(a[r+1][c-1]==d)  count++;
    if(a[r+1][c]==d)  count++;
    if(a[r+1][c+1]==d)  count++;
    return count;
}