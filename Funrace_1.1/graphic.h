#ifndef GRAPHIC__H_
#define GRAPHIC__H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* font;

void renderText(string text, int x,int y,SDL_Color color);

SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);

void renderImage(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer);
#endif // GRAPHIC__H_
