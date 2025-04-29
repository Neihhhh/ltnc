#include<iostream>
#include"XUCXAC.h"
#include<cstdlib>
#include<ctime>
#include "graphic.h"
#include<SDL.h>
#include<vector>
#include<SDL_image.h>
#include"Audio.h"
using namespace std;

const int Distance=70;//ĐỘ DÀI TÍNH CẢ ĐÍCH VÀ VẠCH XUẤT PHÁT
int CELL_SIZE=SCREEN_WIDTH/Distance;
vector<SDL_Point> playerPath={{104,678},{169,678},{232,678},{232,587},{232,510},{299,510},{370,510},
                                  {370,595},{370,680},{438,680},{505,680},{572,680},{572,600},{572,520},
                                  {572,442},{572,357},{572,285},{638,285},{707,285},{707,360},{707,440},
                                  {707,516},{707,600},{707,677},{770,677},{840,677},{905,677},{905,592},
                                  {905,510},{830,510},{830,430},{830,350},{830,260},{830,185},{760,185},
                                  {690,185},{627,185},{560,185},{495,185},{495,255},{495,330},{495,405},
                                  {440,405},{383,405},{383,310},{383,230},{317,230},{253,230},{190,230},
                                  {120,230},{50,230} ,{50,155} ,{50,85}  ,{117,85} ,{180,85} ,{243,85} ,
                                  {307,85} ,{367,85} ,{430,85} ,{493,85} ,{551,85} ,{611,85} ,{673,85} ,
                                  {736,85} ,{800,85} ,{860,85} ,{923,85} ,{923,162},{923,240},{923,305}};

vector<SDL_Point> computerPath={{104,708},{169,708},{232,708},{232,626},{232,540},{299,540},{370,540},
                                          {370,630},{370,710},{438,710},{505,710},{572,710},{572,633},{572,551},
                                          {572,470},{572,392},{572,315},{638,315},{707,315},{707,393},{707,470},
                                          {707,546},{707,630},{707,705},{770,705},{840,705},{905,705},{905,622},
                                          {905,540},{830,540},{830,460},{830,380},{830,290},{830,215},{760,215},
                                          {690,215},{627,215},{560,215},{495,215},{495,285},{495,360},{495,435},
                                          {440,435},{383,435},{383,340},{383,260},{317,260},{253,260},{190,260},
                                          {120,260},{50,260} ,{50,185} ,{50,115} ,{117,115},{180,115},{243,115},
                                          {307,115},{367,115},{430,115},{493,115},{551,115},{611,115},{673,115},
                                          {736,115},{800,115},{860,115},{923,115},{923,192},{923,270},{923,335}};
void renderBoard(){
    SDL_Texture* XX=loadTexture("racemap.jpg",renderer);
    renderImage(XX,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,renderer);

    SDL_Texture* random=loadTexture("random.png",renderer);
    SDL_Texture* boostt=loadTexture("boost.png",renderer);
    SDL_Texture* disautien2buoc=loadTexture("disautien2buoc.png",renderer);
    SDL_Texture* lui2buoc=loadTexture("lui2buoc.png",renderer);
    SDL_Texture* lui3buoc=loadTexture("lui3buoc.png",renderer);
    SDL_Texture* lui10buoc=loadTexture("lui10buoc.png",renderer);
    SDL_Texture* portal=loadTexture("portal.png",renderer);
    SDL_Texture* spboost=loadTexture("spboost.png",renderer);
    SDL_Texture* swapp=loadTexture("swap.png",renderer);
    SDL_Texture* teleport=loadTexture("teleport.png",renderer);
    SDL_Texture* skipturn=loadTexture("matluot1.png",renderer);
    SDL_Texture* x2=loadTexture("x2.png",renderer);
    SDL_Texture* buttoc=loadTexture("buttoc.png",renderer);


    renderImage(boostt,289,510,50,50,renderer);
    renderImage(lui2buoc,360,680,50,50,renderer);
    renderImage(teleport,562,600,50,50,renderer);
    renderImage(portal,playerPath[30].x-10,playerPath[30].y,50,50,renderer);
    renderImage(skipturn,playerPath[16].x-10,playerPath[16].y,50,50,renderer);
    renderImage(x2,playerPath[20].x-10,playerPath[20].y,50,50,renderer);
    renderImage(random,playerPath[24].x-10,playerPath[24].y,50,50,renderer);
    renderImage(random,playerPath[51].x-10,playerPath[51].y,50,50,renderer);
    renderImage(random,playerPath[57].x-10,playerPath[57].y,50,50,renderer);
    renderImage(random,playerPath[65].x-10,playerPath[65].y,50,50,renderer);
    renderImage(random,playerPath[37].x-10,playerPath[37].y,50,50,renderer);
    renderImage(swapp,playerPath[29].x-10,playerPath[29].y,50,50,renderer);
    renderImage(lui3buoc,playerPath[34].x-10,playerPath[34].y,50,50,renderer);
    renderImage(swapp,playerPath[40].x-10,playerPath[40].y,50,50,renderer);
    renderImage(buttoc,playerPath[44].x-15,playerPath[44].y,50,60,renderer);
    renderImage(lui10buoc,playerPath[49].x-10,playerPath[49].y,50,50,renderer);
    renderImage(spboost,playerPath[60].x-10,playerPath[60].y,50,50,renderer);
    renderImage(disautien2buoc,playerPath[67].x-10,playerPath[67].y,50,50,renderer);

    SDL_Texture* dich=loadTexture("dich.png",renderer);
    renderImage(dich,905,300,60,60,renderer);
}



void renderPlayer(int playerStep){

    if(playerStep<0){
        playerStep=0;
    }
    if(playerStep>=Distance){
        playerStep=Distance-1;
    }
    if(playerStep<Distance){
        SDL_Rect Player={playerPath[playerStep].x,playerPath[playerStep].y,25,25};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&Player);
    }
}
void renderComputer(int computerStep){

    if(computerStep<0){
        computerStep=0;
    }
    if(computerStep>=Distance){
        computerStep=Distance-1;
    }
    if(computerStep<Distance){
        SDL_Rect Computer={computerPath[computerStep].x,computerPath[computerStep].y,25,25};
        SDL_SetRenderDrawColor(renderer,0,0,255,255);
        SDL_RenderFillRect(renderer,&Computer);
    }
}
void renderTurn(double resultOTX){
    font = TTF_OpenFont("arial.ttf", 30);
    if(resultOTX==1){
        renderText("Your turn",450,20,{0,255,0});
    }else{
        renderText("Computer's turn",450,20,{0,255,0});
    }
}
void renderDiceNumber(int diceNumber){
    font = TTF_OpenFont("arial.ttf", 24);
    string s=to_string(diceNumber);
    string render="Number dice: ";
    render+=s;
    renderText(render,450,750,{0,255,255});
    SDL_RenderPresent(renderer);
}

const int numberDice[]={1,2,3,4,5,6};
int rollDice(){
    int numberIndex=rand()%6;
    return numberDice[numberIndex];
}

int applyBuffDebuff(int &playerStep,int &playerDiceNumber, int &computerStep, bool &skipTurn) {
    int effect;
    font = TTF_OpenFont("arial.ttf", 24);
    if(playerStep==5){
        effect=0;
    }
    else if(playerStep==8){
        effect=1;
    }
    else if(playerStep==12){
        effect=10;
    }
    else if(playerStep==16){
        effect=8;
    }
    else if(playerStep==20){
        effect=3;
    }
    else if(playerStep==24||playerStep==51||playerStep==57||playerStep==65||playerStep==37){
        effect=rand()%9;
    }
    else if(playerStep==29){
        effect=4;
    }
    else if(playerStep==34){
        effect=2;
    }
    else if(playerStep==40){
        effect=4;
    }
    else if(playerStep==44){
        effect=5;
    }
    else if(playerStep==49){
        effect=9;
    }
    else if(playerStep==60){
        effect=6;
    }
    else if(playerStep==67){
        effect=7;
    }
    else{
        effect=11;
    }

    switch(effect){
        case 0:
            cout<<"di them 2 o"<<endl;
            renderText("Move forward by 2 step",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            playerStep+=2;
            SDL_Delay(1000);
            break;
        case 1:
            cout<<"lui 2 buoc"<<endl;
            renderText("Move back by 2 step",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            playerStep-=2 ;
            break;
        case 2:
            cout<<"neu di dau lui 3 bước"<<endl;
            renderText("If you go first, move back 3 steps",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            if(playerStep>computerStep){
                playerStep-=3;
            }
            break;
        case 3:
            cout<<"x2 so xuc xac"<<endl;
            renderText("x2 dice value",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            playerStep+=playerDiceNumber;
            break;
        case 4:
            cout<<"doi vi tri "<<endl;
            renderText("Switch places",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            swap(playerStep,computerStep);
            break;
        case 5:
            cout<<"neu di dau thi di them 3 o"<<endl;
            renderText("If you go first, move forward 3 steps",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            if(playerStep>computerStep){
                playerStep+=3;
            }
            break;
        case 6:
            cout<<"di them 4 buoc"<<endl;
            renderText("Move back by 1 step",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            playerStep+=4;
            break;
        case 7:
            cout<<"neu di sau thi di them 2 o"<<endl;
            renderText("Move forward 4 steps",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            if(playerStep<computerStep){
                playerStep+=2;
            }
            break;
        case 8:
            cout<<"bo qua luot"<<endl;
            renderText("Skip turn",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            skipTurn=true;
            break;
        case 9:
            cout<<"lui 10 o"<<endl;
            renderText("Move back by 10 step",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            playerStep-=10;
            break;
        case 10:
            cout<<"dich chuyen den o 30";
            renderText("Move to space 30",400,750,{128, 0, 128});
            playBuffdebuffSound();
            SDL_RenderPresent(renderer);
            SDL_Delay(2000);
            playerStep=30;
            break;
        case 11:
            break;
    }
    return effect;
}
void renderXX(int playerStep,int computerStep,double resultOTX){
    SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
    SDL_RenderClear(renderer);
    renderBoard();
    renderPlayer(playerStep);
    renderComputer(computerStep);
    renderTurn(resultOTX);
}
void rollDiceAnimation(SDL_Renderer* renderer, int playerStep, int computerStep, double resultOTX, int playerDiceNumber) {
    SDL_Texture* diceTexture = IMG_LoadTexture(renderer, "sixdiceface.png");
    if (!diceTexture) {
        cout << "Không thể load hình xúc xắc! SDL_image Error: " << IMG_GetError() << endl;
        return;
    }

    int diceFrameWidth = 16;
    int diceFrameHeight = 16;

    SDL_Rect srcRect, destRect;
    srcRect.y = 0;
    srcRect.w = diceFrameWidth;
    srcRect.h = diceFrameHeight;

    destRect.w = 100;
    destRect.h = 100;
    destRect.x = (1000 - destRect.w) / 2;
    destRect.y = (800 - destRect.h) / 2;

    Uint32 startTime = SDL_GetTicks();
    bool animationPlaying = true;

    while (animationPlaying) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - startTime > 2000) {
            animationPlaying = false;
            break;
        }

        int currentFrame = (currentTime / 100) % 6;

        srcRect.x = diceFrameWidth * currentFrame;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        renderXX(playerStep, computerStep, resultOTX);
        SDL_RenderCopy(renderer, diceTexture, &srcRect, &destRect);
        SDL_RenderPresent(renderer);

        SDL_Delay(30);
    }


    srcRect.x = diceFrameWidth * (playerDiceNumber - 1);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    renderXX(playerStep, computerStep, resultOTX);
    SDL_RenderCopy(renderer, diceTexture, &srcRect, &destRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(500);

    SDL_DestroyTexture(diceTexture);
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
                    playButtonSound();
                    waiting = false;
                }
            }
        }
        SDL_Delay(100);
    }
}

void movePlayerStepByStep(int &currentStep, int targetStep, bool isPlayer, int computerStep, int playerStep, double resultOTX) {
    if (currentStep == targetStep) return;

    if (targetStep >= Distance) targetStep = Distance - 1;
    if (targetStep < 0) targetStep = 0;

    int stepDirection = (targetStep > currentStep) ? 1 : -1;
    while (currentStep != targetStep) {
        currentStep += stepDirection;

        if (isPlayer) {
            renderXX(currentStep,computerStep,resultOTX);
        } else {
            renderXX(playerStep,currentStep,resultOTX);
        }
        renderTurn(resultOTX);
        playMoveSound();
        SDL_RenderPresent(renderer);
        SDL_Delay(300);
    }
}
