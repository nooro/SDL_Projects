#include "LU_InputField.h"

LU_InputField::LU_InputField(SDL_Renderer *renderer)
{
    render = renderer;
    if(render == NULL)
        cout << "Failed to create the input field renderer: " << endl;

    type = "normal";

    isActive = false;
    if(TTF_Init() < 0)
        cout << "Failed to initialize TTF: " << TTF_GetError() << endl;

    font = TTF_OpenFont("Resources/Fonts/Chiller.ttf", 999);

    if(font == NULL)
        cout << "Failed to open the font: " << TTF_GetError() << endl;

    SDL_RenderPresent(render);
    textColor = {255, 255, 255, 0};
    inputText = "";
    charLimit = 1;
    isTabPressed = false;
    isEnterPressed = false;
}

LU_InputField::~LU_InputField()
{
    delete(&rect);
    TTF_CloseFont(font);
    TTF_Quit();
}

void LU_InputField::Render()
{
    SDL_RenderCopy(render, texture, NULL, &rect);
    int width = rect.w;
    rect.w = inputText.length() * (width / charLimit);
    SDL_RenderCopy(render, inputTexture, NULL, &rect);
    rect.w = width;
}

void LU_InputField::RenderHover()
{
    SDL_RenderCopy(render, hoverTexture, NULL, &rect);
    int width = rect.w;
    rect.w = inputText.length() * (width / charLimit);
    SDL_RenderCopy(render, inputTexture, NULL, &rect);
    rect.w = width;
}


void LU_InputField::Input(SDL_Event *e)
{
    if(e->type == SDL_KEYDOWN  && isActive)
    {
        if(e->key.keysym.sym == SDLK_BACKSPACE)
        {
            if(inputText.length() > 0)
                Delete();
        }
        else if(e->key.keysym.sym == SDLK_RETURN || e->key.keysym.sym == SDLK_RETURN2)
        {
            isActive = false;
            isEnterPressed = true;
            cout << isEnterPressed;
        }
        else if(e->key.keysym.sym == SDLK_TAB)
        {
            isActive = false;
            isTabPressed = true;
        }
        else
        {
            if(inputText.length() < charLimit)
            {
                inputText += (char)e->key.keysym.sym;

                if(type == "normal")
                    inputTexture = LU_CreateTextTexture(render, inputText, font, textColor);
                else if(type == "password")
                {
                    string passToShow;
                    for(int i = 0; i < inputText.length(); ++i)
                        passToShow += '*';
                    inputTexture = LU_CreateTextTexture(render, passToShow, font, textColor);
                }
            }
        }
    }
}

void LU_InputField::Delete()
{
    inputText.pop_back();
    if(type == "password")
    {
        string passToShow;
        for(int i = 0; i < inputText.length(); ++i)
            passToShow += '*';
        inputTexture = LU_CreateTextTexture(render, passToShow, font, textColor);
    }
    else
        inputTexture = LU_CreateTextTexture(render, inputText, font, textColor);
}

string LU_InputField::GetInputText() { return inputText; }

void LU_InputField::SetCharLimit(int limit) { charLimit = limit; }

void LU_InputField::SetTextColor(int r, int g, int b, int a) { textColor = {r, g, b, a}; }
