#ifndef XUCXAC__H_

#define XUCXAC__H_

#include<iostream>
using namespace std;

extern const int Distance;


void renderBoard();

void renderPlayer(int playerStep);

void renderComputer(int computerStep);

void renderTurn(double resultOTX);

void renderDiceNumber(int diceNumber);

void renderXX(int playerStep,int computerStep,double resultOTX);

void renderResult2(int playerStep,int computerStep);

int rollDice();

bool waitForRestart();

void renderPlayButton();

void waitForPlayButton();

#endif // XUCXAC__H_
