#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include "GUI.h"
#include "../General/General.h"

class Link : public GUI
{
public:
    Link();
    ~Link();
    void SetText(string text, char *font_path, SDL_Color color, SDL_Renderer *renderer);
    void Render(SDL_Renderer *renderer);

private:
    TTF_Font *linkFont = NULL;
    string linkText = "";
    char *fontPath;
    SDL_Renderer *render = NULL;
    SDL_Texture *linkTexture = NULL;
};

#endif // LINK_H_INCLUDED
