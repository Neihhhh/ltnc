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

void rollDiceAnimation(SDL_Renderer* renderer,int playerStep,int computerStep,double resultOTX,int playerDiceNumber);

bool waitForRestart();

void renderPlayButton();

void waitForPlayButton();

int applyBuffDebuff(int &playerStep,int &playerDiceNumber,int& computerStep, bool &skipTurn);

void movePlayerStepByStep(int &currentStep, int targetStep, bool isPlayer, int computerStep, int playerStep, double resultOTX);

#endif // XUCXAC__H_

