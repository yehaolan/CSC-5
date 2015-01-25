/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 25, 2015, 2:15 PM
 * Purpose: Homework assignment4(includeing 7 program)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const float LPRGALN=0.264179;//gallons per liter
const float G=6.673e-8f;//gravitational constant cm^3/g/sec^2

//Function Prototypes
void pg1();
void pg2();
void pg3();
void pg4();
void pg5();
void pg6();
void pg7();
float calMPG(float liter,float dstenc);
float calMPG2();
void InfRt(float lsYrPri,float nowPri);
float atrForc(float,float,float);
void getHat(float weight,float height);//cal and display hat size
void getJkt(float weight,float height,short age);//cal and display jacket size
void getWst(float weight,short age);//cal and display waist size
float caLoan(float pri,float dnPay);//the function to calculate the loan
float caCost(float loan);//the function to calculate the annual cost
float bsMt(float weight);//basal metabolic rate calories required
float pyAt(int intenst,float weight,int time);//physical activity calories required
float calTotCl(float bsMtCal,float pyAtCal);//get the total calories should be consumed

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    char ans;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.Miles Per Gallon"<<endl;
        cout<<"2.Miles Per Gallon2"<<endl;
        cout<<"3.Inflation rate"<<endl;
        cout<<"4.Gravitational attractive force"<<endl;
        cout<<"5.Clothing size"<<endl;
        cout<<"6.New House After-tax cost"<<endl;
        cout<<"7.Caloric Requirement"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        do {
            cout<<"Please select the program(0 to 7)"<<endl;
            cin>>ans;
            if(ans<48||ans>55)
                cout<<"Invalid input"<<endl;
        }while(ans<48||ans>55);

        switch(ans) {
            case '1': pg1(); break;
            case '2': pg2(); break;
            case '3': pg3(); break;
            case '4': pg4(); break;
            case '5': pg5(); break;
            case '6': pg6(); break;
            case '7': pg7(); break;
            case '0': {
                cout<<"This is the end of the program"<<endl;
                break;
            }
        }
        if(ans!='0') {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
            cin.ignore();
        }
    }while(ans!='0');
    
    //Exit stage
    return 0;
}

void pg1() {
    //Savitch_8thEd_Chap4_ProgProj1
    //declare variables
    float gsl;//gasoline of the car
    float dis;//distance
    float mpg;//mile per gallon
    //Prompt user for liters of gasoline of car and the distance
    do {    
        cout<<"Input the number of liters of gasoline consumed by your car"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>gsl;
        if(gsl<=0)
            cout<<"Invalid input"<<endl;
    }while(gsl<=0);
    do {
        cout<<"Input the distance traveled by your car(in miles)"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>dis;
    }while(dis<=0);
    //calculate the result with function
    mpg=calMPG(gsl,dis);
    //Output the result
    cout<<setprecision(2)<<fixed;
    cout<<"With 1 gallon gasoline, your car can travel "<<mpg<<" miles"<<endl;
}

void pg2() {
    //Savitch_8thEd_Chap4_ProgProj2
    //declare variables
    float mpg1,mpg2;//mile per gallon
    //introduce the program
    cout<<"This program can calculate which car "<<endl;
    cout<<"has the best fuel efficiency in two cars"<<endl;
    cout<<"First input the first car, then the second car"<<endl<<endl;
    //calculate the result with function
    mpg1=calMPG2();
    mpg2=calMPG2();
    //Output the result
    cout<<setprecision(2)<<fixed;
    cout<<"With 1 gallon gasoline, first car can travel "<<mpg1<<" miles"<<endl;
    cout<<"With 1 gallon gasoline, second car can travel "<<mpg2<<" miles"<<endl;
    cout<<endl;
    if(mpg1==mpg2)
        cout<<"They have the same fuel efficiency"<<endl;
    else if(mpg1>mpg2)
        cout<<"The first car has the better fuel efficiency"<<endl;
    else
        cout<<"The second car has the better fuel efficiency"<<endl;
}

void pg3() {
    //Savitch_8thEd_Chap4_ProgProj4
    //declare variables
    float lsYrPri, //the price in the last year
          nowPri;  //Today price
    string item;
    //introduce the program
    cout<<"This program gauge the rate of inflation for the past year"<<endl;
    //Prompt user for the price in the last year and today of an item
    cout<<"Please input an item name you would like to gauge the rate of inflation"<<endl;
    cin>>item;
    cout<<"Input the price of "<<item<<" one year ago"<<endl;
    cin>>lsYrPri;
    cout<<"Input the price of "<<item<<" today"<<endl;
    cin>>nowPri;
    //calculate and display the results
    InfRt(lsYrPri,nowPri);
}

void pg4() {
    //Savitch_8thEd_Chap4_ProgProj7
    //declare variable, variables found from Google
    float mEarth=5.972e24f;//mass of earth in Kilograms
    float wtMark=188.0f;//Weight of Mark in lbs
    float rEarth=6.371e3;//radius of earth in kilometers
    //Conversion for consistent units
    mEarth*=1e3;//convert to gram -> 10^3g/kg
    float mMark=wtMark*453.59;//453.59g/lbs
    rEarth*=(1e3f*1e2f);//10^3m/km  10^3cm/m
    //calculate the attractive force in dynes
    float dynes=atrForc(mEarth,mMark,rEarth);
    float lbs=dynes/4.44822e5f;//conversion 1lb/4dynes
    //Output the results
    cout<<"My weight in dynes = "<<dynes<<endl;
    cout<<"My weight in pounds = "<<lbs<<endl;
}

void pg5() {
    //Savitch_8thEd_Chap4_ProgProj9
    //declare variables
    float height, //in inches
          weight, //in pounds
          hat,    //hat size
          jacket, //jacket size
          waist;  //waist size
    unsigned short age;
    //introduce the program
    cout<<"This program can calculate your clothing"<<endl;
    cout<<"sizes with your height,weight and age"<<endl;
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    //Prompt user for height, weight, and age
    cout<<"Please input your weight(pounds), height(inches),and age"<<endl;
    cin>>height>>weight>>age;
    //calculate and display the hat size at one time
    getHat(weight,height);
    //calculate and display the jacket size at one time
    getJkt(weight,height,age);
    //calculate and display the waist size at one time
    getWst(weight,age);
}

void pg6() {
    //Savitch_8thEd_Chap4_ProgProj8
    //declare variables
    float price,   //the price of the house($)
          downPay, //down payment of the house($)
          loan,    //the loan of house($)
          cost;    //annual after-tax cost of new house($)
    //Prompt user for price and down payment
    do {
        cout<<"Input the price of your house($)"<<endl;
        cout<<"Please input the positive number"<<endl;
        cin>>price;
        if(price<=0)
            cout<<"Invalid input"<<endl;
    }while(price<=0);
    do {
        cout<<"Input the down payment of your house($)"<<endl;
        cout<<"Please input the positive number"<<endl;
        cin>>downPay;
        if(downPay<=0)
            cout<<"Invalid input"<<endl;
    }while(downPay<=0);
    //calculate the loan
    loan=caLoan(price,downPay);
    //calculate the cost
    cost=caCost(loan);
    //Output the results
    cout<<"The loan is $"<<loan<<endl;
    cout<<"The annual after-tax cost of new house is $"<<cost<<endl;
}

void pg7() {
    //Savitch_8thEd_Chap4_ProgProj14
    //declare variables
    float weight,//(pounds)
          totCal,//total calories consumed in a meal
          bsMtCal,//calories for basal metabolic
          pyAtCal;//calories for physical activities
    int intenst, //the intensity of physical activities
        time;    //(minutes)time spent performing physical activities
    //introduce program
    cout<<"This program can calculate how many calories should get"<<endl;
    cout<<"in order to maintain the your current weight"<<endl<<endl;
    //Prompt user for weight,intensity,time for physical activity
    cout<<"Here are some sample number of intensity:"<<endl;
    cout<<"***Activity*** |"<<"***Intensity***"<<endl;
    cout<<" Running 10 mph"<<"       17"<<endl;
    cout<<" Running 6  mph"<<"       10"<<endl;
    cout<<" Basketball    "<<"        8"<<endl;
    cout<<" Walking 1  mph "<<"       1"<<endl;
    cout<<"----------input 3 information----------"<<endl;
    cout<<"1.your weight(pounds)"<<endl;
    cout<<"2.activity intensity(positive integer)"<<endl;
    cout<<"3.time for activity(minutes)"<<endl;
    cin>>weight>>intenst>>time;
    //calculate the results
    bsMtCal=bsMt(weight);
    pyAtCal=pyAt(intenst,weight,time);
    totCal=calTotCl(bsMtCal,pyAtCal);
    //Output the results
    cout<<"You need "<<bsMtCal<<" calories for basal metabolic rate"<<endl;
    cout<<"You need "<<pyAtCal<<" calories for physical activity"<<endl;
    cout<<"You need "<<totCal*0.1f<<" calories to digest food"<<endl;
    cout<<"Therefore, you need "<<totCal<<" calories consumed in one day"<<endl;
}

float calMPG(float liter,float dstenc) {
    return dstenc*LPRGALN/liter;
}

float calMPG2() {
    //declare variables
    float gsl, //gasoline of the car
          dis; //distance
    //Prompt user for liters of gasoline of car and the distance
    do {    
        cout<<"Input the number of liters of gasoline consumed by your car"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>gsl;
        if(gsl<=0)
            cout<<"Invalid input"<<endl;
    }while(gsl<=0);
    do {
        cout<<"Input the distance traveled by your car(in miles)"<<endl;
        cout<<"Note:Please input the positive number"<<endl;
        cin>>dis;
    }while(dis<=0);
    return dis*LPRGALN/gsl;
}

void InfRt(float lsYrPri,float nowPri) {
    cout<<setprecision(2)<<fixed;
    cout<<"The rate of inflation is "<<(nowPri-lsYrPri)/lsYrPri*100<<"%"<<endl;
}

float atrForc(float m1,float m2,float d) {
    return G*m1*m2/d/d;
}

void getHat(float weight,float height) {
    cout<<"Your hat size is "<<(2.9*weight/height)<<" inches"<<endl;
}

void getJkt(float weight,float height,short age) {
    float jacket;//jacket size
    jacket=height*weight/288;
    for(int i=39;i<=age;i++) {
        if(i%10==0)
            jacket+=(1.0f/8);
    }
    cout<<"Your jacket size is "<<jacket<<" inches"<<endl;
}

void getWst(float weight,short age) {
    float waist;//waist size
    waist=weight/5.7;
    for(int i=29;i<=age;i++){
        if(i%2==0)
            waist+=0.1;
    }
    cout<<"Your waist size is "<<waist<<" inches"<<endl;
}

float caLoan(float pri,float dnPay) {
    return (pri-dnPay);
}

float caCost(float loan) {
    return (loan*0.03+loan*0.06*(1-0.35));
}

float bsMt(float weight) {
    return 70.0f*pow(weight/2.2,0.756);
}

float pyAt(int intenst,float weight,int time) {
    return 0.0385f*intenst*weight*time;
}

float calTotCl(float bsMtCal,float pyAtCal) {
    return (bsMtCal+pyAtCal)/0.8f;
}