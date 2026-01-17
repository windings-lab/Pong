#include "app_state.h"

#include "SDL3/SDL_video.h"

#include "gl_context.h"

AppState::AppState(SDL_Window* window, OpenGL_Context&& gl_context)
    : window(window)
    , gl_context(std::move(gl_context))
    , sdl_renderer(std::nullopt)
{
}
AppState::AppState(SDL_Window* window, Pong::SDL_Renderer&& sdl_renderer)
    : window(window)
    , gl_context(std::nullopt)
    , sdl_renderer(std::move(sdl_renderer))
{
}

AppState::~AppState()
{
    if (window) SDL_DestroyWindow(window);
}

SDL_Window* AppState::Window() const
{
    return window;
}
OpenGL_Context& AppState::GLContext()
{
    return *gl_context;
}
Pong::SDL_Renderer& AppState::SDL_Renderer()
{
    return *sdl_renderer;
}

