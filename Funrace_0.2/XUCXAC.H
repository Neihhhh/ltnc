#include<iostream>
using namespace std;
void printRace(char a[],int Distance);
int rollDice();
void printResult2(int computerStep,int playerStep,int Distance);
void printCurrentRace(char a[], int Step, int Distance);
void playerTurn(int Distance,char playerRace[],int &playerStep, int &playerDiceNumber,string &rollButtonPlayer);
void computerTurn(int Distance,char computerRace[],int &computerStep,int &computerDiceNumber,string &rollButtonComputer);

