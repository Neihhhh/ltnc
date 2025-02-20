#include <iostream>
#include"OANTUXI.h"
#include"XUCXAC.H"
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    const int Distance=15;

    //in đường đi lúc đầu
    char computerRace[Distance];
    char playerRace[Distance];
    cout<<"PLAYER  : ";
    printRace(playerRace,Distance);
    cout<<"COMPUTER: ";
    printRace(computerRace,Distance);

    //oản tù xì
    string playerChoose;//
    string computerChoose;
    double ResultOTX;
    do{
        cout<<"Choose 1 of 3 things 'Scissors', 'Rock' or 'Paper': ";
        cin>>playerChoose;
        computerChoose=computerChoice();
        cout<<"Computer: "<<computerChoose<<endl;
        printResult1(computerChoose,playerChoose);
    } while(playerChoose==computerChoose);
    ResultOTX=Result1(computerChoose,playerChoose);

    //lắc xúc xắc về đích
    int computerStep=0;
    int playerStep=0;
    int playerDiceNumber;
    int computerDiceNumber;
    string rollButtonPlayer;
    string rollButtonComputer;
    while(computerStep<Distance&&playerStep<Distance){
        if(ResultOTX==1){
            //người lắc
            cout<<"Press 0 to roll the dice: ";
            cin>>rollButtonPlayer;
            playerDiceNumber=rollDice();
            cout<<"Your dice number: "<<playerDiceNumber<<endl;
            playerStep+=playerDiceNumber;
            if (playerStep >= Distance) break;

            //máy lắc
            cout<<"Press 0 to see computer dice: ";
            cin>>rollButtonComputer;
            computerDiceNumber=rollDice();
            cout<<"Computer's dice number: "<<computerDiceNumber<<endl;
            computerStep+=computerDiceNumber;
        } else {
            //người lắc
            cout<<"Press 0 to see computer dice: ";
            cin>>rollButtonComputer;
            computerDiceNumber=rollDice();
            cout<<"Computer's dice number: "<<computerDiceNumber<<endl;
            computerStep+=computerDiceNumber;
            if (computerStep >= Distance) break;

            //máy lác
            cout<<"Press 0 to roll the dice: ";
            cin>>rollButtonPlayer;
            playerDiceNumber=rollDice();
            cout<<"Your dice number: "<<playerDiceNumber<<endl;
            playerStep+=playerDiceNumber;
        }
    }
    printResult2( computerStep, playerStep, Distance);
}
