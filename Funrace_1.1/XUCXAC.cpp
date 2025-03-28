#include<iostream>
#include"XUCXAC.h"
#include<cstdlib>
#include<ctime>
#include "graphic.h"
#include<SDL.h>
using namespace std;

const int Distance=20;//ĐỘ DÀI TÍNH CẢ ĐÍCH VÀ VẠCH XUẤT PHÁT
int CELL_SIZE=SCREEN_WIDTH/Distance;

void renderBoard(){
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    for(int i=1;i<=Distance;i++){
        SDL_RenderDrawLine(renderer,i*CELL_SIZE,300,i*CELL_SIZE,500);
    }
    SDL_RenderDrawLine(renderer,0,SCREEN_HEIGHT/2,SCREEN_WIDTH-CELL_SIZE,SCREEN_HEIGHT/2);
    for(int i=0;i<2;i++){
        SDL_RenderDrawLine(renderer,0,300+i*200,SCREEN_WIDTH,300+i*200);
    }
}
void renderPlayer(int playerStep){
    if(playerStep<0){
        playerStep=0;
    }
    if(playerStep<Distance){
        SDL_Rect Player={playerStep*CELL_SIZE+10,335,30,30};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&Player);
    }
    else{
        SDL_Rect Player={(Distance-1)*CELL_SIZE+10,335,30,30};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&Player);
    }
}
void renderComputer(int computerStep){
    if(computerStep<0){
        computerStep=0;
    }
    if(computerStep<Distance){
        SDL_Rect Computer={computerStep*CELL_SIZE+10,435,30,30};
        SDL_SetRenderDrawColor(renderer,0,0,255,255);
        SDL_RenderFillRect(renderer,&Computer);
    }
    else {
        SDL_Rect Computer={(Distance-1)*CELL_SIZE+10,435,30,30};
        SDL_SetRenderDrawColor(renderer,0,0,255,255);
        SDL_RenderFillRect(renderer,&Computer);
    }
}
void renderTurn(double resultOTX){
    font = TTF_OpenFont("arial.ttf", 24);
    if(resultOTX==1){
        renderText("Your turn",450,150,{0,255,0});
    }else{
        renderText("Computer's turn",450,150,{0,255,0});
    }
}
void renderDiceNumber(int diceNumber){
    string s=to_string(diceNumber);
    string render="Number dice: ";
    render+=s;
    renderText(render,450,200,{0,255,255});
    SDL_RenderPresent(renderer);
}

const int numberDice[]={1,2,3,4,5,6};
int rollDice(){
    int numberIndex=rand()%6;
    return numberDice[numberIndex];
}
void rollDiceAnimation(SDL_Renderer* renderer) {
    SDL_Rect diceRect = {596,200, 25, 25};

    for (int i = 0; i < 30; i++) {
        int randomDice = rand() % 6 + 1;
        renderDiceNumber(randomDice);
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
        SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
        SDL_RenderFillRect(renderer, &diceRect);

    }
}

void applyBuffDebuff(int &playerStep,int &playerDiceNumber) {
    int effect=rand()%100+1;
    cout<<effect<<endl;
    font = TTF_OpenFont("arial.ttf", 24);
    if(effect<=20){
        cout << "di them 1 o"<<endl;
        renderText("Move forward by 1 step",400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerStep++;
        playerStep+=playerDiceNumber;
        SDL_Delay(1000);
    }
    if(effect<=41 && effect>20){
        cout << "lui 1 o"<<endl;
        renderText("Move back by 1 step" ,400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerStep --;
        playerStep+=playerDiceNumber;
    }
    if(effect>41 && effect<=54){
        cout<<"nhan doi xuc xac"<<endl;
        renderText( "Double the dice value",400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerDiceNumber*=2;
        playerStep+=playerDiceNumber;
        SDL_Delay(1000);
    }
    if(effect>54 &&  effect<=67){
        cout<<"di nguoc lai"<<endl;
        renderText("Move in the opposite direction" ,400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerStep-=playerDiceNumber;
        SDL_Delay(1000);
    }
    if(effect>67 &&effect<=80){
        cout<<"cong dich chuyen"<<endl;
        renderText("Random teleport",400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerStep=(int)(rand() / (double)RAND_MAX * 19);
        cout<<playerStep<<endl;
        SDL_Delay(1000);
    }
    if(effect>80 && effect<=100){
        cout<<"lac lai xuc xac"<<endl;
        renderText("Roll the dice again" ,400,600,{0,0,0});
        SDL_RenderPresent(renderer);
        playerDiceNumber = rollDice();
        rollDiceAnimation(renderer);
        renderDiceNumber(playerDiceNumber);
        playerStep+=playerDiceNumber;
        SDL_Delay(1000);
    }


}
void renderXX(int playerStep,int computerStep,double resultOTX){
    SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
    SDL_RenderClear(renderer);
    renderBoard();
    renderPlayer(playerStep);
    renderComputer(computerStep);
    renderTurn(resultOTX);
    SDL_RenderPresent(renderer);
}
void renderResult2(int playerStep,int computerStep){
    SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
    SDL_RenderClear(renderer);
    font = TTF_OpenFont("arial.ttf", 40);
    if(playerStep>=Distance-1){
        renderText("You win!",440,400,{255,0,0});
    } else if(computerStep>=Distance-1){
        renderText("You lost!",440,400,{255,0,0});
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
}

bool waitForRestart() {
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) return false;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_SPACE) return true;
                if (e.key.keysym.sym == SDLK_ESCAPE) return false;
            }
        }
        SDL_Delay(100);
    }
}

void renderPlayButton() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_Texture* background=loadTexture("anhnen.jpg", renderer);
    renderImage(background,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,renderer);

    SDL_Rect playButton = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2-25, 200, 50};
    SDL_SetRenderDrawColor(renderer,200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &playButton);

    renderText("PLAY GAME", SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2 - 10, {255, 255, 255});
    SDL_RenderPresent(renderer);
}

void waitForPlayButton() {
    SDL_Event e;
    bool waiting = true;

    while (waiting) {
        renderPlayButton();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) exit(0);
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x = e.button.x, y = e.button.y;
                if (x >= SCREEN_WIDTH / 2 - 100 && x <= SCREEN_WIDTH / 2 + 100 &&
                    y >= SCREEN_HEIGHT / 2 - 25 && y <= SCREEN_HEIGHT / 2 + 25) {
                    waiting = false;
                }
            }
        }
        SDL_Delay(100);
    }
}

