#include "LU_Button.h"

LU_Button::LU_Button()
{
    buttonFont = TTF_OpenFont("Resources/Fonts/Chiller.ttf", 20);
}

void LU_Button::SetText(char *text, TTF_Font *font, SDL_Renderer *renderer)
{
    buttonText = LU_CreateTextTexture(renderer, text, font, buttonTextColor);
}

void LU_Button::Render(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderCopy(renderer, buttonText, NULL, &rect);
}

void LU_Button::RenderHover(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, hoverTexture, NULL, &rect);
}
