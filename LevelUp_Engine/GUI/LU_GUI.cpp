#include "LU_GUI.h"

LU_GUI::LU_GUI()
{
    rect.x = 0; rect.y = 0;
    rect.w = 0; rect.h = 0;
    texture = NULL;
    hoverTexture = NULL;
    SDL_GetMouseState(&mouseX, &mouseY);
}

LU_GUI::~LU_GUI()
{
    delete(&rect);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(hoverTexture);
}

bool LU_GUI::isClicked(SDL_Event *event)
{
    if(event->type == SDL_MOUSEBUTTONUP && event->button.button == SDL_BUTTON_LEFT)
        return this->isHover();
    return false;
}

bool LU_GUI::isHover()
{
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseX >= rect.x && mouseX <= rect.x + rect.w
        && mouseY >= rect.y && mouseY <= rect.y + rect.h ;
}

int LU_GUI::GetX() { return rect.x; }
int LU_GUI::GetY() { return rect.y; }
int LU_GUI::GetWidth() { return rect.w; }
int LU_GUI::GetHeight() { return rect.h; }

void LU_GUI::SetHeight(int height) { rect.h = height; }
void LU_GUI::SetWidth(int width) { rect.w = width; }
void LU_GUI::SetX(int x) { rect.x = x; }
void LU_GUI::SetY(int y) { rect.y = y; }

void LU_GUI::SetTexture(SDL_Texture *texture) { this->texture = texture; }
void LU_GUI::SetHoverTexture(SDL_Texture *hoverTexture) { this->hoverTexture = hoverTexture; }
