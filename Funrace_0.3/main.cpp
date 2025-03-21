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

    window = SDL_CreateWindow("FunRace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    font = TTF_OpenFont("arial.ttf", 24);
    double resultOTX;
    bool running = true;
    SDL_Event e;
    while (running) {
         do {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            renderOTX();
            SDL_RenderPresent(renderer);

            bool playerHasChosen = false;
            string playerChoose = "";
            string computerChoose = "";

            while (!playerHasChosen && running) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        running = false;
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN && !playerHasChosen) {
                        playerChoose = playerChoice();
                        if (playerChoose != "") {
                            playerHasChosen = true;
                            computerChoose = computerChoice();

                            renderPlayerChoice(playerChoose);
                            renderComputerChoice(computerChoose);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(2000);

                            resultOTX = result1(computerChoose, playerChoose);
                            renderResult1(resultOTX);
                        }
                    }
                }
            }
        } while (resultOTX == 0.5);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        running=false;
    }
    running=true;
    int playerStep=0;
    int computerStep=0;
    renderXX(playerStep,computerStep,resultOTX);
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;

            if (e.type == SDL_KEYDOWN && resultOTX == 1) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    int playerDiceNumber = rollDice();
                    playerStep += playerDiceNumber;
                    renderDiceNumber(playerDiceNumber);
                    SDL_Delay(500);
                    resultOTX = 0;
                    renderXX(playerStep, computerStep, resultOTX);
                }
            }
        }
        if (playerStep >= Distance - 1) {
            renderResult2(playerStep, computerStep);
            break;
        }

        if (resultOTX == 0) { // Máy đi
            SDL_Delay(500);
            int computerDiceNumber = rollDice();
            computerStep += computerDiceNumber;
            renderDiceNumber(computerDiceNumber);
            SDL_Delay(500);
            resultOTX = 1;
            renderXX(playerStep, computerStep, resultOTX);
        }

        if (computerStep >= Distance - 1 ) {
            renderResult2(playerStep, computerStep);
            break;
        }
    }
     SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}
