#ifndef OANTUXI__H_
#define OANTUXI__H_

#include<iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include<SDL.h>
using namespace std;
extern SDL_Rect Scissors;
extern SDL_Rect Rock;
extern SDL_Rect Paper;

bool isMouseInside(SDL_Rect rect, int MouseX, int MouseY);

string playerChoice();

void renderPlayerChoice(string playerChoose);

string computerChoice();

void renderComputerChoice(string computerChoose);

void renderOTX();

double result1(string computerChoose, string playerChoose);

void renderResult1(double resultOTX);

#endif // OANTUXI__H_
