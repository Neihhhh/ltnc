
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

// std::unordered_map<SDL_Keycode, bool> prevKeyState;
bool lastSpacePress = false;

int main(int argc, char* argv[]) {
    while (true) {
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_KEYDOWN) {
            std::cout << "Key pressed\n";
        }
    }
    return 0;
}
