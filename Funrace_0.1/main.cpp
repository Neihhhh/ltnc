#include <iostream>
#include"OANTUXI.h"
#include"XUCXAC.H"
#include<cstdlib>
#include<ctime>
using namespace std;
const int Distance=15;
int main(){
    //in du?ng di lúc d?u
    char computerRace[Distance];
    char playerRace[Distance];
    cout<<"PLAYER  : ";
    printRace(playerRace,Distance);
    cout<<"COMPUTER: ";
    printRace(computerRace,Distance);

    //o?n tù xì
    string playerChoose;//
    string computerChoose;
    double ResultOTX;
    do{
        cout<<"Choose 1 of 3 things 'Scissors'(1), 'Rock'(2) or 'Paper'(3): ";
        cin>>playerChoose;
        playerChoice(playerChoose);
        computerChoose=computerChoice();
        cout<<"ComputerChoice : "<<computerChoose<<endl;
        printResult1(computerChoose,playerChoose);
    } while(playerChoose==computerChoose);
    ResultOTX=Result1(computerChoose,playerChoose);

    //l?c xúc x?c v? dích
    int computerStep=0;
    int playerStep=0;
    int playerDiceNumber;
    int computerDiceNumber;
    string rollButtonPlayer;
    string rollButtonComputer;
    while(computerStep<Distance&&playerStep<Distance){
        if(ResultOTX==1){
            //ngu?i l?c
            cout<<"Press 0 to roll the dice: ";
            cin>>rollButtonPlayer;
            srand(time(0));
            playerDiceNumber=rollDice();
            cout<<"Your dice number: "<<playerDiceNumber<<endl;
            playerStep+=playerDiceNumber;
            cout<<"PLAYER  : ";
            printCurrentRace(playerRace,playerStep,Distance);
            if (playerStep >= Distance) break;

            //máy l?c
            computerDiceNumber=rollDice();
            cout<<"Computer's dice number: "<<computerDiceNumber<<endl;
            computerStep+=computerDiceNumber;
            cout<<"COMPUTER: ";
            printCurrentRace(computerRace,computerStep,Distance);
        } else {
            //máy l?c
            srand(time(0));
            computerDiceNumber=rollDice();
            cout<<"Computer's dice number: "<<computerDiceNumber<<endl;
            computerStep+=computerDiceNumber;
            cout<<"COMPUTER: ";
            printCurrentRace(computerRace,computerStep,Distance);
            if (computerStep >= Distance) break;

            //ngu?i lác
            cout<<"Press 0 to roll the dice: ";
            cin>>rollButtonPlayer;
            playerDiceNumber=rollDice();
            cout<<"Your dice number: "<<playerDiceNumber<<endl;
            playerStep+=playerDiceNumber;
            cout<<"PLAYER  : ";
            printCurrentRace(playerRace,playerStep,Distance );
        }
    }
    printResult2( computerStep, playerStep, Distance);
}
