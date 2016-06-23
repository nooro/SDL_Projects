#include "includes.h"
#include "main.h"
using namespace std;

///MAIN
int main(int args, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create the window
    window = SDL_CreateWindow("Tic-Tac-Toe",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            616,
                            616,
                            SDL_WINDOW_SHOWN);

    //Create the screen
    screen = SDL_GetWindowSurface(window);

    //Draw the grid
    SDL_BlitSurface(grid, NULL, screen, NULL);

    //Update the screen
    SDL_UpdateWindowSurface(window);

    //Go to the main loop
    MainLoop();

    //Free the used memory
    FreeMemory();

return 0;
}

///MAIN LOOP
void MainLoop(){
    do{
        //Regulating the frames per second
        RegulatingFPS(60);

        //Check for events
        Events();

        //Game logic
        GameLogic();
    } while (gameIsRunning == true);
}


///CHECK FOR EVENTS
void Events(){
    if (SDL_PollEvent(&event) == true){
        //Quit button = Escape the program
        if (event.type == SDL_QUIT)
            gameIsRunning = false;

        //Escape button = Escape the program
        if (event.key.keysym.sym == SDLK_ESCAPE)
            gameIsRunning = false;

        //On click draw the player at the right position
        if (event.type == SDL_MOUSEBUTTONDOWN){
            if (event.button.button == SDL_BUTTON_LEFT){
                if (event.button.x > 4 && event.button.y > 4 && event.button.x < 204 && event.button.y < 204 && section[0] == 'n'){
                    DrawThePlayer(4, 4);
                    if(playersTurn == 'r')
                        section[0] = 'b';
                    else if (playersTurn == 'b')
                        section[0] = 'r';
                }
                else if(event.button.y > 4 && event.button.x > 208 && event.button.y < 204 && event.button.x < 408 && section[1] == 'n'){
                    DrawThePlayer(208, 4);
                    if(playersTurn == 'r')
                        section[1] = 'b';
                    else if (playersTurn == 'b')
                        section[1] = 'r';
                }
                else if(event.button.y > 4 && event.button.x > 412 && event.button.y < 204 && event.button.x < 616 && section[2] == 'n'){
                    DrawThePlayer(412, 4);
                    if(playersTurn == 'r')
                        section[2] = 'b';
                    else if (playersTurn == 'b')
                        section[2] = 'r';
                }
                else if(event.button.y > 208 && event.button.x > 4 && event.button.y < 408 && event.button.x < 204 && section[3] == 'n'){
                    DrawThePlayer(4, 208);
                    if(playersTurn == 'r')
                        section[3] = 'b';
                    else if (playersTurn == 'b')
                        section[3] = 'r';
                }
                else if(event.button.y > 208 && event.button.x > 208 && event.button.y < 408 && event.button.x < 408 && section[4] == 'n'){
                    DrawThePlayer(208, 208);
                    if(playersTurn == 'r')
                        section[4] = 'b';
                    else if (playersTurn == 'b')
                        section[4] = 'r';
                }
                else if(event.button.y > 208 && event.button.x > 412 && event.button.y < 408 && event.button.x < 612 && section[5] == 'n'){
                    DrawThePlayer(412, 208);
                    if(playersTurn == 'r')
                        section[5] = 'b';
                    else if (playersTurn == 'b')
                        section[5] = 'r';
                }
                else if(event.button.y > 412 && event.button.x > 4 && event.button.y < 612 && event.button.x < 204 && section[6] == 'n'){
                    DrawThePlayer(4, 412);
                    if(playersTurn == 'r')
                        section[6] = 'b';
                    else if (playersTurn == 'b')
                        section[6] = 'r';
                }
                else if(event.button.y > 412 && event.button.x > 204 && event.button.y < 612 && event.button.x < 404 && section[7] == 'n'){
                    DrawThePlayer(208, 412);
                    if(playersTurn == 'r')
                        section[7] = 'b';
                    else if (playersTurn == 'b')
                        section[7] = 'r';
                }
                else if(event.button.y > 412 && event.button.x > 412 && event.button.y < 612 && event.button.x < 612 && section[8] == 'n'){
                    DrawThePlayer(412, 412);
                    if(playersTurn == 'r')
                        section[8] = 'b';
                    else if (playersTurn == 'b')
                        section[8] = 'r';
                }

                //Computer's artificial intelligence
                //AI();

                //Check for winner
                GameLogic();
            }
        }
    }
}


///DRAW THE PLAYER
void DrawThePlayer(int x, int y){
    playerRect.h = 200;
    playerRect.w = 200;
    playerRect.x = x;
    playerRect.y = y;

    if (playersTurn == 'r'){
        //Draw the red player
        SDL_BlitSurface(red, NULL, screen, &playerRect);
        //Change the player on turn
        playersTurn = 'b';
    }
    else if (playersTurn == 'b'){
        //Draw the red player
        SDL_BlitSurface(blue, NULL, screen, &playerRect);
        //Change the player on turn
        playersTurn = 'r';
    }

    //Update the window
    SDL_UpdateWindowSurface(window);
}

/** THE GAME SECTIONS MAP
    0 | 1 | 2
    - - - - -
    3 | 4 | 5
    - - - - -
    6 | 7 | 8
**/

///GAME LOGIC
void GameLogic(){
    //Check  0-1-2  0-3-6  0-4-8  The main checking number is 0
    if(section[0] != 'n'){
        if (section[0] == section[1] && section[1] == section[2]){
            Winner(0);
        }
        else if (section[0] == section[3] && section[3] == section[6]){
            Winner(0);
        }
        else if (section[0] == section[4] && section[4] == section[8]){
            Winner(0);
        }
    }
    //Check  1-4-7  3-4-5  2-4-6  The main checking number is 4
    if(section[4] != 'n'){
        if (section[1] == section[4] && section[4] == section[7]){
            Winner(4);
        }
        else if (section[3] == section[4] && section[4] == section[5]){
            Winner(4);
        }
        else if (section[2] == section[4] && section[4] == section[6]){
            Winner(4);
        }
    }
    //Check  6-7-8  2-5-8  The main checking number is 8
    if(section[4] != 'n'){
        if (section[6] == section[7] && section[7] == section[8]){
            Winner(8);
        }
        else if (section[2] == section[5] && section[5] == section[8]){
            Winner(8);
        }
    }

    //Check if the game is standoff
    if(section[0] != 'n' && section[1] != 'n' && section[2] != 'n' &&
       section[3] != 'n' && section[4] != 'n' && section[5] != 'n' &&
       section[6] != 'n' && section[7] != 'n' && section[8] != 'n' &&
       gameIsRunning == true){
        //Draw the standoff picture
        winnerRect.x = 0;
        winnerRect.y = 250;
        winnerRect.h = 125;
        winnerRect.w = 616;
        SDL_BlitSurface(winner_standoff, NULL, screen, &winnerRect);

        //Update the window
        SDL_UpdateWindowSurface(window);

        //Delay 2 seconds and close the program
        SDL_Delay(2000);
        gameIsRunning = false;
    }
}


///DRAW THE WINNER
void Winner(int mainCheckingNumber){
    winnerRect.x = 0;
    winnerRect.y = 250;
    winnerRect.h = 125;
    winnerRect.w = 616;

    if(section[mainCheckingNumber] == 'r'){
        //Draw the red winner picture
        SDL_BlitSurface(winner_red, NULL, screen, &winnerRect);

        //Update the window
        SDL_UpdateWindowSurface(window);

        //Delay 1 second and close the program
        SDL_Delay(1000);
        gameIsRunning = false;
    }
    else if(section[mainCheckingNumber] == 'b'){
        //Draw the blue winner picture
        SDL_BlitSurface(winner_blue, NULL, screen, &winnerRect);

        //Update the window
        SDL_UpdateWindowSurface(window);

        //Delay 1 second and close the program
        SDL_Delay(1000);
        gameIsRunning = false;
    }
}


///FREE THE USED MEMORY
void FreeMemory(){
    SDL_DestroyWindow(window);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(grid);
    SDL_FreeSurface(blue);
    SDL_FreeSurface(red);
    SDL_FreeSurface(winner_standoff);
    SDL_FreeSurface(winner_red);
    SDL_FreeSurface(winner_blue);
}


///Artificial intelligence for the computer's turn
void AI(){
    //Check 0-1-2
    if(section[0] == 'n' || section[1] == 'n' || section[2] == 'n'){
        if((section[0] == 'b' && section[1] == 'b') || (section[0] == 'r' && section[1] == 'r')){
            DrawThePlayer(412,4);
            section[2] = 'b';
            MainLoop();
        }
        else if((section[0] == 'b' && section[2] == 'b') || (section[0] == 'r' && section[2] == 'r')){
            DrawThePlayer(208,4);
            section[1] = 'b';
            MainLoop();
        }
        else if((section[1] == 'b' && section[2] == 'b') || (section[1] == 'r' && section[2] == 'r')){
            DrawThePlayer(4,4);
            section[0] = 'b';
            MainLoop();
        }
    }

    //Check 0-4-8
    if(section[0] == 'n' || section[4] == 'n' || section[8] == 'n'){
        if((section[0] == 'b' && section[4] == 'b') || (section[0] == 'r' && section[4] == 'r')){
            DrawThePlayer(412,412);
            section[8] = 'b';
            MainLoop();
        }
        else if((section[0] == 'b' && section[8] == 'b') || (section[0] == 'r' && section[8] == 'r')){
            DrawThePlayer(208,208);
            section[4] = 'b';
            MainLoop();
        }
        else if((section[4] == 'b' && section[8] == 'b') || (section[4] == 'r' && section[8] == 'r')){
            DrawThePlayer(4,4);
            section[0] = 'b';
            MainLoop();
        }
    }

    //Check 0-3-6
    if(section[0] == 'n' || section[3] || section[6] == 'n'){
        if((section[0] == 'b' && section[3] == 'b') || (section[0] == 'r' && section[3] == 'r')){
            DrawThePlayer(4,412);
            section[6] = 'b';
            MainLoop();
        }
        else if((section[0] == 'b' && section[6] == 'b') || (section[0] == 'r' && section[6] == 'r')){
            DrawThePlayer(4,208);
            section[3] = 'b';
            MainLoop();
        }
        else if((section[3] == 'b' && section[6] == 'b') || (section[3] == 'r' && section[6] == 'r')){
            DrawThePlayer(4,4);
            section[0] = 'b';
            MainLoop();
        }
    }

    //Check 3-4-5
    if(section[3] == 'n' || section[4] == 'n' || section[5] == 'n'){
        if((section[3] == 'b' && section[4] == 'b') || (section[3] == 'r' && section[4] == 'r')){
            DrawThePlayer(412,208);
            section[5] = 'b';
            MainLoop();
        }
        else if((section[4] == 'b' && section[5] == 'b') || (section[4] == 'r' && section[5] == 'r')){
            DrawThePlayer(4,208);
            section[3] = 'b';
            MainLoop();
        }
        else if((section[3] == 'b' && section[5] == 'b') || (section[3] == 'r' && section[5] == 'r')){
            DrawThePlayer(208,208);
            section[4] = 'b';
            MainLoop();
        }
    }

    //Check 1-4-7
    if(section[1] == 'n' || section[4] == 'n' || section[7] == 'n'){
        if((section[1] == 'b' && section[4] == 'b') || (section[1] == 'r' && section[4] == 'r')){
            DrawThePlayer(208,412);
            section[7] = 'b';
            MainLoop();
        }
        else if((section[4] == 'b' && section[7] == 'b') || (section[4] == 'r' && section[7] == 'r')){
            DrawThePlayer(208,4);
            section[1] = 'b';
            MainLoop();
        }
        else if((section[1] == 'b' && section[7] == 'b') || (section[1] == 'r' && section[7] == 'r')){
            DrawThePlayer(208,208);
            section[4] = 'b';
            MainLoop();
        }
    }
    ///BIN - RELEASE
    ///1101 0011 1101 1111 1001 1001 0000 1011 0100 1100 0110
    ///1110 0110 0110 1110 0110 0101 1001 1101 1011 1101 1010
    ///0x17FB54 0x55FABC 0xAC1542 0x991ACB
    ///0xBCAEFA 0xA152A5 0x147536 0x010101
    ///1011 1010 1111 0010 1101 1010 0100 1101 1000 0111 1111
    ///0110 1010 0100 0000 1111 1011 1100 1011 1011 1110 0001
    ///0xABC032 0x147536 0xB5A7C4 0x90AF01


    //Check 2-5-8
    if(section[2] == 'n' || section[5] == 'n' || section[8] == 'n'){
        if((section[2] == 'b' && section[5] == 'b') || (section[2] == 'r' && section[5] == 'r')){
            DrawThePlayer(412,412);
            section[8] = 'b';
            MainLoop();
        }
        else if((section[5] == 'b' && section[8] == 'b') || (section[5] == 'r' && section[8] == 'r')){
            DrawThePlayer(412,4);
            section[2] = 'b';
            MainLoop();
        }
        else if((section[2] == 'b' && section[8] == 'b') || (section[2] == 'r' && section[8] == 'r')){
            DrawThePlayer(412,208);
            section[5] = 'b';
            MainLoop();
        }
    }

    //Check 6-7-8
    if(section[6] == 'n' || section[7] == 'n' || section[8] == 'n'){
        if((section[6] == 'b' && section[7] == 'b') || (section[6] == 'r' && section[7] == 'r')){
            DrawThePlayer(412,412);
            section[8] = 'b';
            MainLoop();
        }
        else if((section[7] == 'b' && section[8] == 'b') || (section[7] == 'r' && section[8] == 'r')){
            DrawThePlayer(4,412);
            section[6] = 'b';
            MainLoop();
        }
        else if((section[6] == 'b' && section[8] == 'b') || (section[6] == 'r' && section[8] == 'r')){
            DrawThePlayer(208,412);
            section[7] = 'b';
            MainLoop();
        }
    }

    //Check if the center is empty
    if(section[4] == 'n'){
        DrawThePlayer(208,208);
        section[4] = 'b';
        MainLoop();
    }

    //If the center is full - random position in one of the corners
    else if(section[4] != 'n'){
        //Check if can place at 0 or 2
        if(section[0] == 'n' || section[2] == 'n'){
            if(section[0] != 'n' && section[2] == 'n'){
                DrawThePlayer(412,4);
                MainLoop();
            }
            else if(section[2] != 'n' && section[0] == 'n'){
                DrawThePlayer(4,4);
                MainLoop();
            }
            else if(section[0] == 'n' && section[2] == 'n'){
                RandomPosition();
                if(RandomPosition() == 1){
                    DrawThePlayer(4,4);
                    MainLoop();
                }
                else{
                    DrawThePlayer(412,4);
                    GameLogic();
                }
            }
        }

        //Check if can place at 6 or 8
        else if(section[6] == 'n' || section[8] == 'n'){
            if(section[6] != 'n' && section[8] == 'n'){
                DrawThePlayer(4,412);
                MainLoop();
            }
            else if(section[8] != 'n' && section[8] == 'n'){
                DrawThePlayer(412,412);
                MainLoop();
            }
            else if(section[6] == 'n' && section[8] == 'n'){
                RandomPosition();
                if(RandomPosition() == 1){
                    DrawThePlayer(4,412);
                    MainLoop();
                }
                else{
                    DrawThePlayer(412,412);
                    MainLoop();
                }
            }
        }
    }

    if((section[0] != 'n' || section[8] != 'n') && (section[2] == 'n' || section[6] == 'n')){
        if(section[2] == 'n' && section[6] != 'n'){
            DrawThePlayer(412,4);
            MainLoop();
        }
        else if(section[6] == 'n' && section[2] != 'n'){
            DrawThePlayer(4,412);
            MainLoop();
        }
        else if(section[2] == 'n' && section[6] == 'n'){
            RandomPosition();
            if(RandomPosition() == 1)
                DrawThePlayer(412,4);
            else
                DrawThePlayer(4,412);

            MainLoop();
        }
    }

    else if((section[2] != 'n' || section[6] != 'n') && (section[0] == 'n' || section[8] == 'n')){
        if(section[0] == 'n' && section[8] != 'n'){
            DrawThePlayer(4,4);
            MainLoop();
        }
        else if(section[8] == 'n' && section[0] != 'n'){
            DrawThePlayer(412,412);
            MainLoop();
        }
        else if(section[0] == 'n' && section[8] == 'n'){
            RandomPosition();
            if(RandomPosition() == 1)
                DrawThePlayer(4,4);
            else
                DrawThePlayer(412,412);

            MainLoop();
        }
    }
}

///Random position for suggested cells
int RandomPosition(){
    int random;
    srand(time(0));

    random = 1+(rand()%2);

    if(random == 1)
        return 1;
    else
        return 2;
}
