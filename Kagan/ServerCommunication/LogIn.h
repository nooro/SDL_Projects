#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <windows.h>
#include "ServerCommunication.h"
#include "../GUI/Button.h"
#include "../GUI/InputField.h"
#include "../GUI/Link.h"
using namespace std;

class LogIn
{
public:
    LogIn(); //Initialize everything for the log-in. Create log-in window with fields to enter user-name and password. Send the data to the server.
    ~LogIn(); //Free the used memory.
    char Status(); //Return if the log-in is successful or not.

private:
    char *serverIP = SERVER_IP;

    SDL_Texture *inputFieldTexture = NULL;
    SDL_Texture *inputFieldTextureHover = NULL;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;

    SDL_Texture *windowBorder = NULL;
    SDL_Texture *logoTexture = NULL;
    SDL_Rect logoRect;
    SDL_Texture *backgroundTexture = NULL;

    TTF_Font *labelFont;
    SDL_Texture *usernameLabel;
    SDL_Texture *passwordLabel;
    SDL_Rect usernameLabelRect;
    SDL_Rect passwordLabelRect;
    SDL_Color labelColor;

    InputField *usernameInputField;
    InputField *passwordInputField;

    Button logInButton;
    SDL_Texture *buttonTexture = NULL;
    SDL_Texture *buttonHoverTexture = NULL;
    SDL_Texture *buttonText = NULL;

    bool logInWindowIsActive;
    void Loop();
    void InitTheButton();
    void InitTheInputFields();
    void InitTheTextures();
    void InitTheRegistrationLink();
    char status;

    SDL_Color linkColor;
    Link registrationLink;
};

#endif // LOGIN_H_INCLUDED
