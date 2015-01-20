/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on January 19, 2015, 6:40 PM
 * Purpose: Assignment3(9 program)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const char CONVPT = 100;
const float CAR_DIO = 258.0;//speed of sound in carbon dioxide
const float AIR = 331.5;//speed of sound in air
const float HELIUM = 972.0;//speed of sound in helium
const float HYDGN = 1270.0;//speed of sound in hydrogen

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    char pg;
    do{
        //display the menu and prompt user for opening program
        cout<<"---------------Assignment 3---------------"<<endl;
        cout<<"***************Program Menu***************"<<endl;
        cout<<"1.Body Mass Index"<<endl;
        cout<<"2.Software Sales"<<endl;
        cout<<"3.The Speed of Sound in Gases"<<endl;
        cout<<"4.Paper-rock-scissor game"<<endl;
        cout<<"5.Quadratic equation"<<endl;
        cout<<"6.Blackjack"<<endl;
        cout<<"7.Green Crud population"<<endl;
        cout<<"8.Prime Number"<<endl;
        cout<<"9.Celsius and Fahrenheit"<<endl;
        cout<<"0.End the program"<<endl<<endl;
        cout<<"Which program you want to open"<<endl;
        cin>>pg;
        
        switch(pg) {
            case '0': {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            case '1': {
                //Gaddis_7thEd_Chap4_ProgChal5
                //declare variables
                short weight,
                      height;
                float BMI;
                //Prompt user for weight and height
                do {
                    cout << "Please input your weight(pounds)" << endl;
                    cout << "Please input a positive number" << endl;
                    cin >> weight;
                }while(weight<=0);

                do {
                    cout << "Please input your height(inches)" << endl;
                    cout << "Please input a positive number" << endl;
                    cin >> height;
                }while(height<=0);
                //calculate the BMI
                BMI = static_cast<float>(weight)*703/height/height;
                //determine the BMI level
                if(BMI>=18.5&&BMI<=25)
                    cout << "Congratulation! Your weight is optimal." << endl;
                if(BMI<18.5)
                    cout << "Sorry! You are considered to be underweight." << endl;
                if(BMI>25)
                    cout << "Sorry! You are considered to be overweight." << endl;
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '2': {
                //Gaddis_7thEd_Chap4_ProgChal10
                //declare variables
                short retail = 99;//the retail of a package($)
                short unit;//the number of units sold
                float cost;//total cost of the purchase
                char dscnt;//quantity discount
                //Prompt user for the number of units
                do {
                  cout << "How many unit of package have been sold?" <<endl;
                  cin >> unit;
                  if(unit<=0)
                      cout << "Please input the positive number" << endl;
                } while(unit<=0);//make sure the number of unit is positive
                //determine the discount
                if(unit>=100) {
                    dscnt = 50;
                } else if(unit>=50) {
                    dscnt = 40;
                } else if(unit>=20) {
                    dscnt = 30;
                } else if(unit>=10) {
                    dscnt = 20;
                } else {
                    dscnt = 0;
                }
                //calculate the total cost
                cost = retail*unit*(1-static_cast<float>(dscnt)/CONVPT);
                //Output the result
                cout << setprecision(2) << fixed;
                cout << "The total cost of the purchase is $" << cost << endl;
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '3': {
                //Gaddis_7thEd_Chap4_ProgChal19
                //declare variables
                char select;//which choice user select
                short time;//the time of sound go through
                float dist;//the distance of sound have gone through
                string medium;//the string of 4 medium
                float speed;//the speed of sound in a certain medium

                //introduce the program and display the menu for user to select
                cout << "This program can calculate the distance of " << endl;
                cout << "sound go through in certain time." << endl;
                cout << "***************The Gas Menu***************" << endl;
                cout << "1. Carbon Dioxide" << endl;
                cout << "2. Air" << endl;
                cout << "3. Helium" << endl;
                cout << "4. Hydrogen" << endl;

                do {
                    cout << "Please input 1-4 for selecting" << endl;
                    cin >> select;
                } while(select<'1'||select>'4');
                //select the medium

                switch(select) {
                    case '1'://carbon dioxide
                        medium = "carbon dioxide";
                        speed = CAR_DIO;
                        break;
                    case '2'://air
                        medium = "air";
                        speed = AIR;
                        break;
                    case '3'://helium
                        medium = "helium";
                        speed = HELIUM;
                        break;
                    case '4'://hydrogen
                        medium = "hydrogen";
                        speed = HYDGN;
                        break;
                    default://tell user it is invalid choice
                        cout << "This is invalid choice." << endl;
                        cout << "Please run this program again and select from 1 - 4." << endl;
                }
                //tell user which medium has been selected, and prompt user for time
                cout << "You have selected " << medium << endl;
                cout << "Input the time of sound travels(seconds)" << endl;
                cout << "Please input a positive integer between 0 and 30" << endl;
                //require the time is between 0 and 30 seconds
                do {
                    cin >> time;
                    if(time<0||time>30)
                        cout << "Please input the time between 0 and 30 seconds" << endl;
                } while(time<0||time>30);

                //calculate the distances
                dist = time*speed;

                //Output the result
                cout << "The distance of sound went through in " << medium  << endl;
                cout << "in " << time << " seconds is " << dist << " meters" << endl;
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '4': {
                //Savitch_8thEd_Chap3_ProgProj1
                //declare variables
                char p1,//player1
                     p2;//player2
                //introduce the program
                cout<<"Paper-rock-scissor game"<<endl;
                cout<<"After input two players' gesture, this program can determine who win"<<endl;
                //prompt user for first player's gesture
                do{
                    cout<<"Input the first player's gesture"<<endl;
                    cout<<"Note:Only input P,R, or S"<<endl;
                    cin>>p1;
                    if(p1!='p'&&p1!='r'&&p1!='s'&&p1!='P'&&p1!='R'&&p1!='S')
                        cout<<"Invalid input"<<endl;
                }while(p1!='p'&&p1!='r'&&p1!='s'&&p1!='P'&&p1!='R'&&p1!='S');
                //if it is upper case,change it to lowercase
                if(p1<91)
                    p1+=32;
                //prompt user for second player's gesture
                do{
                    cout<<"Input the second player's gesture"<<endl;
                    cout<<"Note:Only input P,R, or S"<<endl;
                    cin>>p2;
                    if(p2!='p'&&p2!='r'&&p2!='s'&&p2!='P'&&p2!='R'&&p2!='S')
                        cout<<"Invalid input"<<endl;
                }while(p2!='p'&&p2!='r'&&p2!='s'&&p2!='P'&&p2!='R'&&p2!='S');
                //if it is upper case,change it to lowercase
                if(p2<91)
                    p2+=32;
                //compare two gesture
                if(p1==p2){
                    //when they equal,nobody wins
                    cout<<"Nobody wins"<<endl;
                } else if(p1+p2==226){
                    //when sum is 226, means paper and rock
                    cout<<"Paper cover rock"<<endl;
                    if(p1==112)
                        //when p1 is paper
                        cout<<"Player1 win"<<endl;
                    else
                        //when p1 is not paper
                        cout<<"Player2 win"<<endl;
                } else if(p1+p2==227){
                    //when sum is 227, means paper and scissors
                    cout<<"Scissors cut paper"<<endl;
                    if(p1==115)
                        //when p1 is scissor
                        cout<<"Player1 win"<<endl;
                    else
                        //when p1 is not scissor
                        cout<<"Player2 win"<<endl;
                } else {
                    //in other situation,means rock and scissor
                    cout<<"Rock breaks scissors"<<endl;
                    if(p1==114)
                        //when p1 is rock
                        cout<<"Player1 win"<<endl;
                    else
                        //when p1 is not rock
                        cout<<"Player2 win"<<endl;
                }
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '5': {
                //Savitch_8thEd_Chap3_ProgProj6
                //declare variables
                short a,//Quadratic Term
                      b,//First Term
                      c;//constant term
                float dscrmnt;//discriminant
                float root;
                char ans;
                //introduce program
                cout << "This program solves quadratic equation to finds its boots" << endl;
                cout << "The quadratic equation likes ax^2+bx+c=0(a not equal to 0)" << endl;
                do {
                    //prompt user for a,b,c these three number
                    cout << "Please input the number of a,b,c" << endl;
                    cout << "Quadratic term a cannot be zero" << endl;
                    //Limit a cannot be 0
                    do {
                        cin >> a >> b >> c;
                        if(a==0) {
                            cout << "a cannot be zero" << endl;
                            cout << "Input a,b,c one more time" <<endl;
                        }
                    } while(a==0);
                    //display the quadratic equation
                    cout << "The quadratic equation looks like ";
                    cout <<a<<"x^2" <<(b<0?"":"+")<<b<<"x"<<(c<0?"":"+")<<c<<"=0"<<endl;
                    //calculate the discriminant
                    dscrmnt = b*b-4*a*c;
                    //determine how many roots quadratic equation has and calculate the root(s)
                    if(dscrmnt<0) {
                        //no real root
                        cout << "This quadratic equation doesn't have real root" << endl;
                    } else if(dscrmnt==0) {
                        //when discriminant equals to 0, quadratic equation has a single root
                        cout << "This quadratic equation has a single real root" << endl;
                        //calculate the root
                        root = 0.5f*(-b)/a;
                        //Output the root
                        cout << "The single real root is " << root << endl;
                    } else {
                       //when discriminant greater to 0, quadratic equation has two real roots 
                       cout << "This quadratic equation has two real roots" << endl;
                       //calculate first root and output first root
                       root = 0.5f*(-b+sqrt(dscrmnt))/a;
                       cout << "The root 1 is " << root << endl;
                       //calculate second root and output second root
                       root = 0.5f*(-b-sqrt(dscrmnt))/a;
                       cout << "The root 2 is " << root << endl;
                    }
                    cout << "Would you like to run the program again? 'Y' for yes,'N' for no."<< endl;
                    cin >> ans;
                } while(ans=='y'||ans=='Y');
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '6': {
                //Savitch_8thEd_Chap3_ProgProj8
                //declare variables and initialize 
                char crd;      //the kind of the card
                short crdPtB;  //the bigger point of card
                short crdPtS;  //the smaller point of card
                short valueB=0;  //the bigger total value(ace count 11)
                short valueS=0;  //the smaller total value(ace count 1)
                short crdNum;  //the number of cards user has

                //introduce program and prompt user for the number of cards he has
                cout << "This program scores a blackjack hand" << endl;
                do {
                    cout << "How many cards you have?(an integer between 2 and 5)";
                    cin >> crdNum;
                    if(crdNum<2||crdNum>5)
                        cout << "The range is from 2 to 5" << endl;
                } while(crdNum<2||crdNum>5);
                //introduce how to input the card
                cout << "When you input the card from ace,2,...,queen,king" << endl;
                cout << "You should input a,2,3,4,5,6,7,8,9,t,j,q, or k" << endl;
                cout << "Press Enter to continue" << endl;
                cin.ignore();
                //use a loop to ask user for card and calculate the value
                for(int i=1;i<=crdNum;i++) {
                    crdPtB=0;
                    crdPtS=0;
                    cout<<"Input the card"<<i<<": ";
                    cin>>crd;
                    //card 2-9
                    if(crd>=50&&crd<=57) {
                        crdPtB=static_cast<short>(crd)-48;
                        crdPtS=static_cast<short>(crd)-48;
                    } else if(crd=='t'||crd=='j'||crd=='q'||crd=='k'||crd=='T'||crd=='J'||crd=='Q'||crd=='K'){
                        //card 10,jack,queen,king
                        crdPtB=10;
                        crdPtS=10;
                    } else if(crd=='a'||crd=='A') {
                        //card ace
                        crdPtB=11;
                        crdPtS=1;
                    } else {
                        //other card is invalid
                        cout<<"You have input the invalid card"<<endl;
                        cout<<"Please input again"<<endl;
                        i--;
                    } 
                    valueB+=crdPtB;
                    valueS+=crdPtS;
                }
                //when the smaller total value greater than 21, means busted
                if(valueB>21&&valueS>21) {
                    cout<<"Busted"<<endl;
                } else if(valueB>21&&valueS<=21) {
                    //the bigger total value greater than 21,but smaller value not,get the smaller one
                    cout<<"You get "<<valueS<<endl;
                } else {
                    //bigger and smaller total value both less than 21,get the bigger one
                    cout<<"You get "<<valueB<<endl;
                }
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '7': {
                //Savitch_8thEd_Chap3_ProgProj10
                //declare and initialize variables
                unsigned int initPo;//initial population
                unsigned int lstTwoP;//last two population
                unsigned int lastPo=0;//last population
                unsigned int currPo;//current population
                short day;
                //introduce the program
                cout<<"The Fibonacci series applies to green crud population"<<endl;
                cout<<"The population is the same for 4 days and then increase every fifth day"<<endl;
                //Prompt user for initial population
                do {
                    cout<<"Input the initial population(in pounds)"<<endl;
                    cout<<"Note:Input positive integer between 1 and 100"<<endl;
                    cin>>initPo;
                } while(initPo<1||initPo>100);
                //Prompt user for the number of days
                do {
                    cout<<"Input the number of days"<<endl;
                    cout<<"Note:Input positive integer between 1 and 100"<<endl;
                    cin>>day;
                } while(day<1||day>100);
                //initial population assign to last two population
                lstTwoP=initPo;
                //user for loop to calculate the population at a certain day
                for(int i=0;i<=day;i++){
                    //every fifth days
                    if(i%5==0) {
                        currPo=lstTwoP+lastPo;//equal to the total of last two days 
                        lstTwoP=lastPo;
                        lastPo=currPo;
                        cout<<"Day"<<i<<": "<<currPo<<" pounds"<<endl; 
                    } else {
                        //the other day
                        currPo=lastPo;//the same of last day's
                        cout<<"Day"<<i<<": "<<currPo<<" pounds"<<endl;
                    }

                }
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            case '8': {
                //Savitch_8thEd_Chap3_ProgProj14
                //introduce program
                cout<<"This program finds and prints all the prime number s between 3 and 100"<<endl;
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                cout<<"Prime numbers are:"<<endl;
                //the outer loop is to count from 3 to 100
                for(int num=3;num<=100;num++){ 
                    //the inner loop to check if this number is prime number
                    for(int div=2;div<num;div++){
                        //if number can be divided by divisor, means this number is not prime number
                        if(num%div==0)
                            break;
                        else if(num==div+1) {
                            //when until number equal to divisor+1,means this number is prime number, so output
                            cout<<num<<endl;
                        }
                    }
                }
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                break;
            }
            case '9': {
                //Savitch_8thEd_Chap3_ProgProj16
                //declare and initialize variables
                int cls=100;//Celsius temperature
                int fhr=212;    //Fahrenheit temperature
                //introduce this program
                cout<<"This program use do-while to find out"<<endl;
                cout<<"the same temperature in both Celsius and Fahrenheit"<<endl;
                cout<<"Press Enter to continue"<<endl;
                cin.ignore();
                //use do-while loop to find out the same temperature
                do{
                    cls--;
                    fhr=32+cls*9/5;  
                }while(fhr!=cls);
                //Output the result
                cout<<"The same temperature in both Celsius and Fahrenheit is "<<cls<<endl;
                cout<<"Press Enter to Continue"<<endl;
                cin.ignore();
                break;
            }
            
        }

    }while(pg!='0');
    //Exit stage right
    return 0;
}

