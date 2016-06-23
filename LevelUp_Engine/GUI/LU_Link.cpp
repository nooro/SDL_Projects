#include "LU_Link.h"

LU_Link::LU_Link()
{

}

LU_Link::~LU_Link()
{
    delete(linkFont);
}

void LU_Link::SetText(string text, char *font_path, SDL_Color color, SDL_Renderer *renderer)
{
    linkText = text;
    fontPath = font_path;

    linkFont = TTF_OpenFont(font_path, 999);
    if(linkFont == NULL)
        cout << "Failed to open the LU_Link font: " << TTF_GetError() << endl;

    render = renderer;

    linkTexture = LU_CreateTextTexture(render, text, linkFont, color);
}

void LU_Link::Render(SDL_Renderer *renderer) { SDL_RenderCopy(renderer, linkTexture, NULL, &rect); }
