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

void playerChoice(string &playerChoose){
    if(playerChoose=="1"){
        playerChoose="Scissors";
    } else if(playerChoose=="2"){
        playerChoose="Rock";
    } else {
        playerChoose="Paper";
    }
    cout<<"PlayerChoice :"<<playerChoose<<endl;
}

double Result1(string computerChoose, string playerChoose){
    if((computerChoose=="Rock" && playerChoose=="Paper")||(computerChoose=="Paper" &&playerChoose=="Scissors")||(computerChoose=="Scissors" && playerChoose=="Rock")){
        return 1;//người chơi thắng
    }
    else if(computerChoose==playerChoose){
        return 0.5;
    }
    return 0;//người chơi thua
}

void printResult1(string computerChoose, string playerChoose){
    if(Result1( computerChoose, playerChoose)==1){
        cout<<"You win. You go first.";
    }
    else if(Result1( computerChoose, playerChoose)==0.5){
        cout<<"Draw!";
    }
    else{
        cout<<"You lose. You go second.";
    }
    cout<<endl;
}




