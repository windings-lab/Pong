#include <string>

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>

#include "test.h"

auto counter_class = Test();

int         aaaaa = 12;
float       b = 23;
std::string ccc;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    counter_class.counter++;
    SDL_Log("Test: %d", counter_class.counter);

    SDL_Delay(16);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_Quit();
}
