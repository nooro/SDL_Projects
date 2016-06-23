#include "Game.h"

void Game::LoadTheResources()
{
    //background texture
    background_texture = CreateTexture("Resources/Textures/home-window/bg.jpg", renderer);
    if(background_texture == NULL)
        cout << "Failed to create the background texture: " << SDL_GetError() << endl;
}
