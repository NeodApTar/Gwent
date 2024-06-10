#include "font.h"
TTF_Font* MainMenuFont;
SDL_Color black = { 0,0,0 };
SDL_Color white = { 255,255,255 };
void TextInit()
{
	char TextDir[] = "font.ttf";
	TTF_Init();
	MainMenuFont = TTF_OpenFont(TextDir,100);
}
void MenuText(SDL_Renderer* render, TTF_Font* font, SDL_Color color, int cordx, int cordy,int h,int w, const char* text)
{
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderUTF8_Blended(font, text, color);
	SDL_Rect rect;
	rect.x = cordx;
	rect.y = cordy;
	rect.w = w;
	rect.h = h;
	SDL_Texture* Texture_font = SDL_CreateTextureFromSurface(render, textSurface);

	SDL_RenderCopy(render, Texture_font, NULL, &rect);
	
	SDL_DestroyTexture(Texture_font);
	SDL_FreeSurface(textSurface);
	
}