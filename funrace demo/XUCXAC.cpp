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
    srand(time(0));
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

