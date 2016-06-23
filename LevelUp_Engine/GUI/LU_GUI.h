#ifndef LU_GUI_H_INCLUDED
#define LU_GUI_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class LU_GUI
{
public:
    LU_GUI();
    ~LU_GUI();

    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();

    int mouseX, mouseY;

    void SetX(int x);
    void SetY(int y);
    void SetWidth(int width);
    void SetHeight(int height);

    void SetTexture(SDL_Texture *texture);
    void SetHoverTexture(SDL_Texture *hoverTexture);

    bool isHover();
    bool isClicked(SDL_Event *event);

    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_Texture *hoverTexture;
};

#endif // LU_GUI_H_INCLUDED
