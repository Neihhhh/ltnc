#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphic.h"
#include "OANTUXI.h"
#include "XUCXAC.h"
using namespace std;
const int Distance=15;
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    srand(time(0));

    window = SDL_CreateWindow("FunRace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        cout << "Failed to load font! Error: " << TTF_GetError() << endl;
        return -1;
    }
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
        running=false;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    char computerRace[Distance];
    char playerRace[Distance];
    cout<<"PLAYER  : ";
    printRace(playerRace,Distance);
    cout<<"COMPUTER: ";
    printRace(computerRace,Distance);

    int computerStep=0;
    int playerStep=0;
    int playerDiceNumber;
    int computerDiceNumber;
    string rollButtonPlayer;
    string rollButtonComputer;
    while(computerStep<Distance&&playerStep<Distance){
        if(resultOTX==1){
            //người lắc
            srand(time(0));
            playerTurn(Distance,playerRace,playerStep,playerDiceNumber,rollButtonPlayer);
            if (playerStep >= Distance) break;
            //máy l?c
            computerTurn(Distance,computerRace,computerStep,computerDiceNumber,rollButtonComputer);
        } else {
            //máy l?c
            srand(time(0));
            computerTurn(Distance,computerRace,computerStep,computerDiceNumber,rollButtonComputer);
            if (computerStep >= Distance) break;
            playerTurn(Distance,playerRace,playerStep,playerDiceNumber,rollButtonPlayer);
            //ngu?i lác

        }
    }
    printResult2( computerStep, playerStep, Distance);
}


