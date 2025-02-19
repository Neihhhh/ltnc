#include<iostream>
#include"XUCXAC.h"
#include<cstdlib>
#include<ctime>
using namespace std;

const int Distance=15;
char a[Distance];
void printRace(){
    for(int i=0;i<Distance;i++){
        a[i]='_';
    }
    for(int i=0;i<Distance;i++){
        cout<<a[i];
    }
    cout<<"!";
}

const int numberDice[]={1,2,3,4,5,6};
int rollDice(){
    srand(time(0));
    int numberIndex=rand()%6;
    return numberDice[numberIndex];
}
