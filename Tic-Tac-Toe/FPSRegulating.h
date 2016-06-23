#ifndef FPSREGULATING_H_INCLUDED
#define FPSREGULATING_H_INCLUDED

    int testingTick;

    ///REGULATING THE PRAMES PER SECOND
    void RegulatingFPS(int FPS){
        testingTick = SDL_GetTicks();
        if((1000/FPS) > (SDL_GetTicks() - testingTick))
            SDL_Delay ((1000/FPS) - (SDL_GetTicks() - testingTick));
    }

#endif // FPSREGULATING_H_INCLUDED
