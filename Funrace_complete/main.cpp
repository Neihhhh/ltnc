#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphic.h"
#include "OANTUXI.h"
#include "XUCXAC.h"
#include "Audio.h"
#include <SDL_image.h>

using namespace std;

bool lastSpacePress = false;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    InitAudio();

    srand(time(0));

    window = SDL_CreateWindow("FunRace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("arial.ttf", 24);

    playBackgroundMusic();

    bool running = true;
    while (running){
        int gameState = -1;
        double resultOTX = 0.5;
        int playerStep = 38, computerStep = 0;
        SDL_Event e;
        bool skipTurnPlayer=false;
        bool skipTurnComputer=false;

        if (gameState == -1) {
            waitForPlayButton();
            gameState = 0;
        }
        while (gameState != 2) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    exit(0);
                    break;
                }
                if (gameState == 0) {
                    renderOTX();
                    SDL_RenderPresent(renderer);
                    bool playerHasChosen = false;
                    string playerChoose = "", computerChoose = "";
                    while (!playerHasChosen && running) {
                        while (SDL_PollEvent(&e)) {
                            if (e.type == SDL_QUIT) {
                                exit(0);
                                break;
                            }
                            if (e.type == SDL_MOUSEBUTTONDOWN) {
                                playButtonSound();
                                playerChoose = playerChoice();
                                if (playerChoose!="") {
                                    playerHasChosen = true;

                                    computerChoose = computerChoice();

                                    renderPlayerChoice(playerChoose);
                                    renderComputerChoice(computerChoose);
                                    SDL_RenderPresent(renderer);
                                    SDL_Delay(500);

                                    resultOTX = result1(computerChoose, playerChoose);

                                    renderResult1(resultOTX);

                                    if (resultOTX != 0.5 ) gameState = 1;
                                }
                            }
                        }
                    }
                } else if (gameState == 1) {
                    renderXX(playerStep, computerStep, resultOTX);
                    SDL_RenderPresent(renderer);
                    if (e.type == SDL_QUIT) {
                        exit(0);
                        break;
                    }

                    else if (e.type == SDL_KEYUP) {
                        lastSpacePress = false;
                    }

                    else if (e.type == SDL_KEYDOWN && resultOTX == 1 ) {
                        if (e.key.keysym.sym == SDLK_SPACE && !lastSpacePress ) {

                            lastSpacePress = true;

                            int playerDiceNumber = rollDice();
                            playDiceRollSound();
                            rollDiceAnimation(renderer,playerStep,computerStep,resultOTX,playerDiceNumber);
                            renderDiceNumber(playerDiceNumber);
                            SDL_Delay(1000);

                            int targetStep = playerStep + playerDiceNumber;
                            movePlayerStepByStep(playerStep, targetStep, true, computerStep, playerStep, resultOTX);

                            int oldPlayerStep = playerStep;
                            int effect=applyBuffDebuff(playerStep,playerDiceNumber,computerStep,skipTurnPlayer);

                            if (effect == 4 || effect == 10) {
                                renderXX(playerStep, computerStep, resultOTX);
                                SDL_RenderPresent(renderer);
                            } else if(playerStep != oldPlayerStep){
                                movePlayerStepByStep(oldPlayerStep, playerStep, true, computerStep, playerStep, resultOTX);
                            }

                            if (playerStep >= Distance - 1) {
                                pauseMusic();
                                playWinSound();
                                renderResult2(playerStep, computerStep);
                                SDL_Delay(1000);
                                gameState = 2;
                                resumeMusic();
                                break;
                            }
                            if(skipTurnComputer==true){
                                resultOTX=1;
                                skipTurnComputer=false;
                            }
                            else{
                                resultOTX=0;
                            }

                            renderXX(playerStep, computerStep, resultOTX);
                            SDL_RenderPresent(renderer);
                        }
                    }
                    if (resultOTX == 0) {

                        SDL_Delay(500);
                        int computerDiceNumber = rollDice();
                        playDiceRollSound();
                        rollDiceAnimation(renderer,playerStep,computerStep,resultOTX,computerDiceNumber);
                        renderDiceNumber(computerDiceNumber);
                        SDL_Delay(1000);

                        int targetStep = computerStep + computerDiceNumber;
                        movePlayerStepByStep(computerStep, targetStep, false, computerStep, playerStep, resultOTX);

                        int oldComputerStep = computerStep;
                        int effect=applyBuffDebuff(computerStep,computerDiceNumber,playerStep,skipTurnComputer);

                        if (effect == 4 || effect == 10) {
                            renderXX(playerStep, computerStep, resultOTX);
                            SDL_RenderPresent(renderer);
                        }else if(computerStep != oldComputerStep){
                            movePlayerStepByStep(oldComputerStep, computerStep, false, computerStep, playerStep, resultOTX);
                        }

                        if( skipTurnPlayer==true){
                            resultOTX=0;
                            skipTurnPlayer=false;
                        }
                        else{
                            resultOTX=1;
                        }

                        renderXX(playerStep, computerStep, resultOTX);
                        SDL_RenderPresent(renderer);
                    }
                    if (computerStep >= Distance - 1) {
                        pauseMusic();
                        playLoseSound();
                        renderResult2(playerStep, computerStep);
                        SDL_Delay(1000);
                        resumeMusic();
                        gameState = 2;
                    }
                }
            }
        }
        font = TTF_OpenFont("arial.ttf", 24);
        renderText("Press SPACE to play again, ESC to exit", 300, 500, {0,0,0});
        SDL_RenderPresent(renderer);
        running = waitForRestart();
    }
    cleanupAudio();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
