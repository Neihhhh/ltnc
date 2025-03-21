#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphic.h"
#include "OANTUXI.h"
#include "XUCXAC.h"

using namespace std;


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    srand(time(0));

    window = SDL_CreateWindow("FunRace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("arial.ttf", 24);

    bool running = true;

    while (running) {
        int gameState = -1;
        double resultOTX = 0.5;
        int playerStep = 0, computerStep = 0;
        SDL_Event e;

        if (gameState == -1) {
            waitForPlayButton();
            gameState = 0;
        }

        while (gameState != 2) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    running = false;
                    gameState = 2;
                    break;
                }

                if (gameState == 0) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    renderOTX();
                    SDL_RenderPresent(renderer);

                    bool playerHasChosen = false;
                    string playerChoose = "", computerChoose = "";

                    while (!playerHasChosen && running) {
                        while (SDL_PollEvent(&e)) {
                            if (e.type == SDL_QUIT) { running = false; break; }
                            if (e.type == SDL_MOUSEBUTTONDOWN) {
                                playerChoose = playerChoice();
                                if (playerChoose!="") {
                                    playerHasChosen = true;
                                    computerChoose = computerChoice();

                                    renderPlayerChoice(playerChoose);
                                    renderComputerChoice(computerChoose);
                                    SDL_RenderPresent(renderer);
                                    SDL_Delay(1000);

                                    resultOTX = result1(computerChoose, playerChoose);
                                    renderResult1(resultOTX);
                                    if (resultOTX != 0.5) gameState = 1;
                                }
                            }
                        }
                    }
                } else if (gameState == 1) {
                    renderXX(playerStep, computerStep, resultOTX);

                    if (e.type == SDL_KEYDOWN && resultOTX == 1) {
                        if (e.key.keysym.sym == SDLK_SPACE) {
                            int playerDiceNumber = rollDice();
                            playerStep += playerDiceNumber;
                            renderDiceNumber(playerDiceNumber);
                            SDL_Delay(500);
                            renderXX(playerStep, computerStep, resultOTX);
                            if (playerStep >= Distance - 1) {
                                renderResult2(playerStep, computerStep);
                                SDL_Delay(100);
                                gameState = 2;
                                break;
                            }

                        resultOTX = 0;
                        renderXX(playerStep, computerStep, resultOTX);
                        }
                    }

                    if (resultOTX == 0) {
                        SDL_Delay(500);
                        int computerDiceNumber = rollDice();
                        computerStep += computerDiceNumber;
                        renderDiceNumber(computerDiceNumber);
                        SDL_Delay(500);
                        resultOTX = 1;
                        renderXX(playerStep, computerStep, resultOTX);
                    }

                    if (computerStep >= Distance - 1) {
                        renderResult2(playerStep, computerStep);
                        SDL_Delay(1000);
                        gameState = 2;
                    }
                }
            }
        }

        renderText("Press SPACE to play again, ESC to exit", 300, 500, {255, 255, 255});
        SDL_RenderPresent(renderer);
        running = waitForRestart();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
