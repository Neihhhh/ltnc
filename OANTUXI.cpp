#include"OANTUXI.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const string THING_LIST[]={"Rock", "Scissors", "Paper"};

string computerChoice(){
    srand(time(0));
    int randomIndex = rand() % 3;
    return THING_LIST[randomIndex];
}

void printResult(string computerChoose, string playerChoose){
    if((computerChoose=="Rock" && playerChoose=="Paper")||(computerChoose=="Paper" &&playerChoose=="Scissors")||(computerChoose=="Scissors" && playerChoose=="Rock")){
        cout<<"You win. You go first.";
    }
    else{
        cout<<"You lose. You go second.";
    }
}




