#include<iostream>
#include"XUCXAC.h"
#include<cstdlib>
#include<ctime>
#include "graphic.h"
using namespace std;

const int Distance=20;//ĐỘ DÀI TÍNH CẢ ĐÍCH VÀ VẠCH XUẤT PHÁT
int CELL_SIZE=SCREEN_WIDTH/Distance;

void renderBoard(){
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    for(int i=1;i<=Distance;i++){
        SDL_RenderDrawLine(renderer,i*CELL_SIZE,300,i*CELL_SIZE,500);
    }
    SDL_RenderDrawLine(renderer,0,SCREEN_HEIGHT/2,SCREEN_WIDTH-CELL_SIZE,SCREEN_HEIGHT/2);
    for(int i=0;i<2;i++){
        SDL_RenderDrawLine(renderer,0,300+i*200,SCREEN_WIDTH,300+i*200);
    }
    SDL_RenderPresent(renderer);
}
void renderPlayer(int playerStep){
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
    SDL_RenderPresent(renderer);
}
void renderComputer(int computerStep){
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
    SDL_RenderPresent(renderer);
}
void renderTurn(double resultOTX){
    font = TTF_OpenFont("arial.ttf", 30);
    if(resultOTX==1){
        renderText("Your turn",450,150,{0,255,0});
    }else{
        renderText("Computer's turn",450,150,{0,255,0});
    }
    SDL_RenderPresent(renderer);
}
void renderDiceNumber(int diceNumber){
    string s=to_string(diceNumber);
    string render="Number dice: ";
    render+=s;
    renderText(render,450,200,{0,255,255});
    SDL_RenderPresent(renderer);
}
void renderXX(int playerStep,int computerStep,double resultOTX){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    renderBoard();
    renderPlayer(playerStep);
    renderComputer(computerStep);
    renderTurn(resultOTX);
}
void renderResult2(int playerStep,int computerStep){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    font = TTF_OpenFont("arial.ttf", 40);
    if(playerStep>=Distance-1){
        renderText("You win!",460,400,{255,0,0});
    } else if(computerStep>=Distance-1){
        renderText("You lost!",460,400,{255,0,0});
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}
const int numberDice[]={1,2,3,4,5,6};
int rollDice(){
    int numberIndex=rand()%6;
    return numberDice[numberIndex];
}
