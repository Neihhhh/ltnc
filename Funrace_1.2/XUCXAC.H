#ifndef XUCXAC__H_

#define XUCXAC__H_

#include<iostream>
#include<SDL.h>
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

void rollDiceAnimation(SDL_Renderer* renderer);

bool waitForRestart();

void renderPlayButton();

void waitForPlayButton();

void applyBuffDebuff(int &playerStep,int &playerDiceNumber,int& computerStep, bool &skipTurn);

#endif // XUCXAC__H_

