#include<iostream>
#include"XUCXAC.h"
#include<cstdlib>
#include<ctime>
using namespace std;
void printRace(char a[],int Distance){
    for(int i=0;i<Distance;i++){
        a[i]='_';
    }
    for(int i=0;i<Distance;i++){
        cout<<a[i];
    }
    cout<<"!";
    cout<<endl;
}

const int numberDice[]={1,2,3,4,5,6};
int rollDice(){
    int numberIndex=rand()%6;
    return numberDice[numberIndex];
}

void printResult2(int computerStep,int playerStep,int Distance){
    if(computerStep>=Distance){
        cout<<"You lost!";
    }
    else if(playerStep>=Distance){
        cout<<"Congratulation! You win.";
    }
    cout<<endl;
}
void printCurrentRace(char a[], int Step, int Distance){
    for(int i=0;i<Step;i++){
        a[i]='|';
    }
    for(int i=0;i<Distance;i++){
        cout<<a[i];
    }
    cout<<"!";
    cout<<endl;
}
void playerTurn(int Distance,char playerRace[],int &playerStep, int &playerDiceNumber,string &rollButtonPlayer){
    cout<<"Press 0 to roll the dice: ";
    cin>>rollButtonPlayer;
    playerDiceNumber=rollDice();
    cout<<"Your dice number: "<<playerDiceNumber<<endl;
    playerStep+=playerDiceNumber;
    cout<<"PLAYER  : ";
    printCurrentRace(playerRace,playerStep,Distance);
}
void computerTurn(int Distance,char computerRace[],int &computerStep,int &computerDiceNumber,string &rollButtonComputer){
    computerDiceNumber=rollDice();
    cout<<"Computer's dice number: "<<computerDiceNumber<<endl;
    computerStep+=computerDiceNumber;
    cout<<"COMPUTER: ";
    printCurrentRace(computerRace,computerStep,Distance);
}

