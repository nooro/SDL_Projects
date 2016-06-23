#ifndef LU_OBJECT_H_INCLUDED
#define LU_OBJECT_H_INCLUDED

#include "LevelUp.h"

class LU_Object
{
private:
    SDL_Rect rect;
    bool isVisible;
    bool isDragable;
    bool isDragging;
    bool isDynamic;
    SDL_Texture *texture;

public:
    LU_Object(int x, int y, int w, int h);
    ~LU_Object();

    int GetX();
    int GetY();
    int GetW();
    int GetH();

    void SetX(int value);
    void SetY(int value);
    void SetW(int value);
    void SetH(int value);

    bool IsHover();

    void MakeVisible();
    void MakeInvisible();
    void MakeStatic();
    void MakeDynamic();

    bool IsVisible();
    bool IsDragable();
    bool IsDragging();
    bool IsDynamic();

    void AddTexture(std::string path);

    SDL_Texture *GetTexture();
    SDL_Rect *GetRect();

    void Drag();
};

#endif // LU_OBJECT_H_INCLUDED
