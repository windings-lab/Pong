#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>

#include "app_state.h"


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    SDL_SetLogPriority(SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_INFO);

    SDL_SetAppMetadata("Pong", "1.0.0", nullptr);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("%s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    const char* title = "Pong";
    int width = 800;
    int height = 600;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(title, width, height, 0, &window, &renderer);
    if (!window || !renderer) {
        SDL_Log("%s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    *appstate = new AppState(window, Pong::SDL_Renderer(window, renderer));
    renderer = nullptr;
    window = nullptr;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    auto* state = static_cast<AppState*>(appstate);

    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    auto* state = static_cast<AppState*>(appstate);

    state->SDL_Renderer().Iterate();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    auto* state = static_cast<AppState*>(appstate);

    delete state;
    state = nullptr;

    SDL_Quit();
}
