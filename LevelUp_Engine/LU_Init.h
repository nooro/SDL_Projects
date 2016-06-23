#ifndef LU_INIT_H_INCLUDED
#define LU_INIT_H_INCLUDED

#include "LevelUp.h"
#include <windows.h>

#define UP 0x0001
#define RIGHT 0x0010
#define DOWN 0x0100
#define LEFT 0x1000

SDL_Event LU_Event;
SDL_Renderer *LU_Renderer = NULL;
SDL_Window *LU_Window = NULL;

int LU_NumberOfObjects;

int GetScreenHeight();
int GetScreenWidth();

SDL_Texture *LU_CreateTexture(std::string filePath, SDL_Renderer *textureRenderer);
SDL_Texture *LU_CreateTextTexture(SDL_Renderer* renderer, std::string text, TTF_Font *font, SDL_Color textColor);

#endif // LU_INIT_H_INCLUDED
