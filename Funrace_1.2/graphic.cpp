#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphic.h"
#include<SDL_image.h>
using namespace std;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;

void renderText(string text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) {
        cout << "Text rendering failed: " << TTF_GetError() << endl;
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (!texture) {
        cout << "Bug image " << IMG_GetError() << endl;
    }
    return texture;
}

void renderImage(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer) {
    if (!texture) return;

    SDL_Rect dstRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}

