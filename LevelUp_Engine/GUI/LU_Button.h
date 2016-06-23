#ifndef LU_BUTTON_H_INCLUDED
#define LU_BUTTON_H_INCLUDED

#include "../LevelUp.h"

using namespace std;

class LU_Button : public LU_GUI
{
public:
    LU_Button();
    void SetText(char *text, TTF_Font *font, SDL_Renderer *renderer);
    void Render(SDL_Renderer *renderer);
    void RenderHover(SDL_Renderer *renderer);

private:
    SDL_Texture *buttonText;
    TTF_Font *buttonFont;
    SDL_Color buttonTextColor;
};

#endif // LU_BUTTON_H_INCLUDED
