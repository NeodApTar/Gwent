#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
extern TTF_Font* MainMenuFont;
extern SDL_Color black;
extern SDL_Color white;
char TextDir[];
void TextInit();
void MenuText(SDL_Renderer* render, TTF_Font* font, SDL_Color color, int cordx, int cordy,int h,int w,const char* text);
