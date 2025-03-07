#include"OANTUXI.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "graphic.h"
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;
SDL_Rect Scissors = {100, 100, 200, 100};
SDL_Rect Rock = {400, 100, 200, 100};
SDL_Rect Paper = {700, 100, 200, 100};

bool isMouseInside(SDL_Rect rect, int MouseX, int MouseY) {
    return (MouseX >= rect.x && MouseX <= rect.x + rect.w &&MouseY >= rect.y && MouseY <= rect.y + rect.h);
}

string playerChoice() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (isMouseInside(Scissors, mouseX, mouseY)) return "Scissors";
    if (isMouseInside(Rock, mouseX, mouseY)) return "Rock";
    if (isMouseInside(Paper, mouseX, mouseY)) return "Paper";
    return "";
}

void renderPlayerChoice(string playerChoose) {
    SDL_Rect Playerchoose = {400, 350, 200, 100};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Playerchoose);
    renderText("You:", 320, 390, {255, 255, 255});
    renderText(playerChoose, 450, 390, {255, 255, 255});
}

const string THING_LIST[] = {"Rock", "Scissors", "Paper"};

string computerChoice() {
    return THING_LIST[rand() % 3];
}

void renderComputerChoice(string computerChoose) {
    SDL_Rect Computerchoose = {400, 500, 200, 100};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Computerchoose);
    renderText("Computer:", 280, 540, {255, 255, 255});
    renderText(computerChoose, 460, 540, {255, 255, 255});
}

void renderOTX() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Scissors);
    renderText("Scissors", 150, 140, {255, 255, 255});

    SDL_RenderDrawRect(renderer, &Rock);
    renderText("Rock", 470, 140, {255, 255, 255});

    SDL_RenderDrawRect(renderer, &Paper);
    renderText("Paper", 770, 140, {255, 255, 255});

    SDL_RenderPresent(renderer);
}

double result1(string computerChoose, string playerChoose) {
    if ((computerChoose == "Rock" && playerChoose == "Paper") ||
        (computerChoose == "Paper" && playerChoose == "Scissors") ||
        (computerChoose == "Scissors" && playerChoose == "Rock")) {
        return 1;
    } else if (computerChoose == playerChoose) {
        return 0.5;
    }
    return 0;
}

void renderResult1(double resultOTX) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (resultOTX == 1) {
        renderText("You win. You go first.", 450, 400, {255, 255, 255});
    } else if (resultOTX == 0) {
        renderText("You lose. You go second.", 450, 400, {255, 255, 255});
    } else {
        renderText("Draw! Play again.", 450, 400, {255, 255, 255});
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(1500);
}

