#ifndef LU_LINK_H_INCLUDED
#define LU_LINK_H_INCLUDED

#include "../LevelUp.h"
using namespace std;

class LU_Link : public LU_GUI
{
public:
    LU_Link();
    ~LU_Link();
    void SetText(string text, char *font_path, SDL_Color color, SDL_Renderer *renderer);
    void Render(SDL_Renderer *renderer);

private:
    TTF_Font *linkFont = NULL;
    string linkText = "";
    char *fontPath;
    SDL_Renderer *render = NULL;
    SDL_Texture *linkTexture = NULL;
};

#endif // LU_LINK_H_INCLUDED
