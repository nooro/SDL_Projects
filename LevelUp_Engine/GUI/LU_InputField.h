#ifndef LU_INPUTFIELD_H_INCLUDED
#define LU_INPUTFIELD_H_INCLUDED

#include "../LevelUp.h"
using namespace std;

class LU_InputField : public LU_GUI
{
public:
    LU_InputField(SDL_Renderer *render);
    ~LU_InputField();

    string type;

    void Render();
    void RenderHover();

    void Input(SDL_Event *e);

    string GetInputText();
    bool isActive;

    void SetCharLimit(int limit);
    void SetTextColor(int r, int g, int b, int a);

    bool isTabPressed;
    bool isEnterPressed;
private:
    SDL_Renderer *render = NULL;
    SDL_Texture *inputFieldTexture;

    SDL_Color textColor;
    TTF_Font *font = NULL;
    SDL_Texture *inputTexture = NULL;

    string inputText = "";
    int charLimit;

    void Delete();
};

#endif // LU_INPUTFIELD_H_INCLUDED
