#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>

#include "app_state.h"
#include "rhi/sdl_renderer.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    SDL_SetLogPriority(SDL_LOG_CATEGORY_SYSTEM, SDL_LOG_PRIORITY_INFO);

    SDL_SetAppMetadata("Pong", "1.0.0", nullptr);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("%s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    constexpr const char* title = "Pong";
    constexpr int width = 800;
    constexpr int height = 600;

    SDL_Window* sdl_window;
    SDL_Renderer* sdl_renderer;
    SDL_CreateWindowAndRenderer(title, width, height, 0, &sdl_window, &sdl_renderer);
    if (!sdl_window || !sdl_renderer) {
        SDL_Log("%s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    auto window = Window(sdl_window);
    auto* as = new AppState(std::move(window), std::make_unique<Pong::SDL_Renderer>(sdl_renderer));
    *appstate = as;
    sdl_renderer = nullptr;
    sdl_window = nullptr;

    as->OnInitialize();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    auto* state = static_cast<AppState*>(appstate);
    return state->HandleEvent(event);
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    auto* state = static_cast<AppState*>(appstate);

    state->Iterate();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    auto* state = static_cast<AppState*>(appstate);

    delete state;
    state = nullptr;

    SDL_Quit();
}
