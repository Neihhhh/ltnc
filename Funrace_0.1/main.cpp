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
            //người lắc
            srand(time(0));
            playerTurn(Distance,playerRace,playerStep,playerDiceNumber,rollButtonPlayer);
            if (playerStep >= Distance) break;
            //máy l?c
            computerTurn(Distance,computerRace,computerStep,computerDiceNumber,rollButtonComputer);
        } else {
            //máy l?c
            srand(time(0));
            computerTurn(Distance,computerRace,computerStep,computerDiceNumber,rollButtonComputer);
            if (computerStep >= Distance) break;
            playerTurn(Distance,playerRace,playerStep,playerDiceNumber,rollButtonPlayer);
            //ngu?i lác

        }
    }
    printResult2( computerStep, playerStep, Distance);
}
