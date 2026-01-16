#include "app_state.h"

#include <SDL3/SDL_video.h>

AppState::AppState(SDL_Window* window) : window(window)
{

}

AppState::~AppState()
{
    SDL_DestroyWindow(window);
}
