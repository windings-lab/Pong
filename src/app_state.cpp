#include "app_state.h"

#include "SDL3/SDL_video.h"

#include "rhi/gl_context.h"

AppState::AppState(SDL_Window* window)
    : window(window)
    , gl_context(std::nullopt)
    , sdl_renderer(std::nullopt)
    , active_renderer(nullptr)
{
}

AppState::AppState(SDL_Window* window, OpenGL_Context&& gl_context)
    : AppState(window)
{
    this->gl_context.emplace(std::move(gl_context));
    active_renderer = &*this->gl_context;
}
AppState::AppState(SDL_Window* window, Pong::SDL_Renderer&& sdl_renderer)
    : AppState(window)
{
    this->sdl_renderer.emplace(std::move(sdl_renderer));
    active_renderer = &*this->sdl_renderer;
}

AppState::~AppState()
{
    if (window) SDL_DestroyWindow(window);
}
void AppState::Iterate()
{
    active_renderer->Iterate(pong_scene);
}

SDL_Window* AppState::Window() const
{
    return window;
}
Renderer* AppState::renderer()
{
    return active_renderer;
}
