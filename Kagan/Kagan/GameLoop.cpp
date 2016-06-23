#include "Game.h"

void Game::GameLoop()
{
    while(gameIsRunning)
    {
        SDL_RenderCopy(renderer, background_texture, NULL, NULL);
        CheckForEvents();
        SDL_RenderPresent(renderer);
    }
}
