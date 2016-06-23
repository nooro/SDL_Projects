#include "LU_Object.h"

LU_Object::LU_Object(int x = 0, int y = 0, int w = 0, int h = 0)
{
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        isVisible = true;
        isDragging = false;
        isDynamic = false;
}

LU_Object::~LU_Object()
{
    //free(&rect);
    //delete (&rect);
    SDL_DestroyTexture(texture);
}

int LU_Object::GetX() { return rect.x; }
int LU_Object::GetY() { return rect.y; }
int LU_Object::GetW() { return rect.w; }
int LU_Object::GetH() { return rect.h; }

void LU_Object::SetX(int value) { rect.x = value; }
void LU_Object::SetY(int value) { rect.y = value; }
void LU_Object::SetW(int value) { rect.w = value; }
void LU_Object::SetH(int value) { rect.h  = value; }

bool LU_Object::IsHover()
{
    return LU_Event.button.x >= rect.x && LU_Event.button.x <= rect.x + rect.w
        && LU_Event.button.y >= rect.y && LU_Event.button.y <= rect.y + rect.h;
}

void LU_Object::MakeVisible() { isVisible = true; }
void LU_Object::MakeInvisible() { isVisible = false; }
void LU_Object::MakeStatic() { isDynamic = false; }
void LU_Object::MakeDynamic() { isDynamic = true; }

bool LU_Object::IsVisible() { return isVisible; }
bool LU_Object::IsDragable() { return isDragable; }
bool LU_Object::IsDragging() { return isDragging; }
bool LU_Object::IsDynamic() { return isDynamic; }

void LU_Object::AddTexture(std::string path)
{
    texture = LU_CreateTexture(path, LU_Renderer);
}

SDL_Texture *LU_Object::GetTexture() { return texture; }
SDL_Rect *LU_Object::GetRect() { return &rect; }


void LU_Object::Drag()
{
    //Drag the element
    if(LU_Event.type == SDL_MOUSEMOTION && isDragging == true)
    {
        rect.x = LU_Event.button.x - rect.w / 2;
        rect.y = LU_Event.button.y - rect.h / 2;
    }

    //Drop the element
    else if(LU_Event.type == SDL_MOUSEBUTTONUP && isDragging == true)
    {
        isDragging = false;
    }

    //Take the element
    else if(LU_Event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(LU_Event.button.button == SDL_BUTTON_LEFT && this->IsHover())
        {
            isDragging = true;
        }
    }
}
