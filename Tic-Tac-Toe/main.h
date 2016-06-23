#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;
    SDL_Event event;

    SDL_Surface* blue = SDL_LoadBMP("resources\\images\\blue.bmp");
    SDL_Surface* red = SDL_LoadBMP("resources\\images\\red.bmp");
    SDL_Surface* grid = SDL_LoadBMP("resources\\images\\grid.bmp");
    SDL_Surface* winner_red = SDL_LoadBMP("resources\\images\\winner_red.bmp");
    SDL_Surface* winner_blue = SDL_LoadBMP("resources\\images\\winner_blue.bmp");
    SDL_Surface* winner_standoff = SDL_LoadBMP("resources\\images\\winner_standoff.bmp");

    SDL_Rect winnerRect;
    SDL_Rect playerRect;

    bool gameIsRunning = true;
    char section[9] = {'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'}; // n - nothing, r - red, b - blue
    char playersTurn = 'r'; // r - red, b - blue

///FUNCTIONS
    void Winner(int mainCheckingNumber);
    void DrawThePlayer(int x, int y);
    void FreeMemory();
    void GameLogic();
    void MainLoop();
    void Events();
    void AI();

    int RandomPosition();
#endif // MAIN_H_INCLUDED
