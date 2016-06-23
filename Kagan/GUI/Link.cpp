#include "Link.h"

Link::Link()
{

}

Link::~Link()
{
    delete(linkFont);
}

void Link::SetText(string text, char *font_path, SDL_Color color, SDL_Renderer *renderer)
{
    linkText = text;
    fontPath = font_path;

    linkFont = TTF_OpenFont(font_path, 999);
    if(linkFont == NULL)
        cout << "Failed to open the link font: " << TTF_GetError() << endl;

    render = renderer;

    linkTexture = CreateTextTexture(render, text, linkFont, color);
}

void Link::Render(SDL_Renderer *renderer) { SDL_RenderCopy(renderer, linkTexture, NULL, &rect); }
