#include"OANTUXI.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "graphic.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include<SDL_image.h>
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
    SDL_Texture* green=loadTexture("green.png", renderer);

    SDL_Texture* scissorsImage=loadTexture("scissors.png", renderer);
    SDL_Texture* paperImage=loadTexture("paper.png", renderer);
    SDL_Texture* rockImage=loadTexture("rock.png", renderer);

    renderImage(green,400, 350, 200, 100,renderer);
    renderText("You:", 320, 390, {0,0,0});

    if(playerChoose=="Scissors"){
        renderImage(scissorsImage,450,350,100,100,renderer);
    }
    if(playerChoose=="Paper"){
        renderImage(paperImage,450,350,100,100,renderer);
    }
    if(playerChoose=="Rock"){
        renderImage(rockImage,450,350,100,100,renderer);
    }
}

const string THING_LIST[] = {"Rock", "Scissors", "Paper"};

string computerChoice() {
    return THING_LIST[rand() % 3];
}

void renderComputerChoice(string computerChoose) {
    SDL_Texture* green=loadTexture("green.png", renderer);

    SDL_Texture* scissorsImage=loadTexture("scissors.png", renderer);
    SDL_Texture* paperImage=loadTexture("paper.png", renderer);
    SDL_Texture* rockImage=loadTexture("rock.png", renderer);

    renderImage(green,400, 500, 200, 100,renderer);

    renderText("Computer:", 280, 540, {0,0,0});

    if(computerChoose=="Scissors"){
        renderImage(scissorsImage,450,500,100,100,renderer);
    }
    if(computerChoose=="Paper"){
        renderImage(paperImage,450,500,100,100,renderer);
    }
    if(computerChoose=="Rock"){
        renderImage(rockImage,450,500,100,100,renderer);
    }
}


void renderOTX() {
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    font = TTF_OpenFont("arial.ttf", 24);

    SDL_Texture* scissorsImage=loadTexture("scissors.png", renderer);
    SDL_Texture* paperImage=loadTexture("paper.png", renderer);
    SDL_Texture* rockImage=loadTexture("rock.png", renderer);

    SDL_Texture* green=loadTexture("green.png", renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);

    renderImage(green,100, 100, 200, 100,renderer);
    renderImage(scissorsImage,150,100,100,100,renderer);
    renderText("Scissors",160, 200, {0,0,0});

    renderImage(green,400, 100, 200, 100,renderer);
    renderImage(rockImage,450,100,100,100,renderer);
    renderText("Rock", 470, 200, {0,0,0});

    renderImage(green,700, 100, 200, 100,renderer);
    renderImage(paperImage,750,100,100,100,renderer);
    renderText("Paper", 770, 200, {0,0,0});

}

double result1(string computerChoose, string playerChoose) {
    if ((computerChoose == "Rock" && playerChoose == "Paper") || (computerChoose == "Paper" && playerChoose == "Scissors") || (computerChoose == "Scissors" && playerChoose == "Rock")) {
        return 1;//NGUOI THANG
    } else if (computerChoose == playerChoose) {
        return 0.5;
    }
    return 0;//MAY TNANG
}

void renderResult1(double resultOTX) {
    font = TTF_OpenFont("arial.ttf", 42);
    if (resultOTX == 1) {
        renderText("You win. You go first.", 300, 700, {0,0,0});
    } else if (resultOTX == 0) {
        renderText("You lose. You go second.", 300, 700, {0,0,0});
    } else {
        renderText("Draw! Play again.", 300, 700, {0,0,0});
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}


