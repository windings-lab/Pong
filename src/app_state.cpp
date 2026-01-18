#include "app_state.h"

#include "SDL3/SDL_video.h"

#include "rhi/gl_context.h"

AppState::AppState(Window&& window)
    : m_window(std::move(window))
    , gl_context(std::nullopt)
    , sdl_renderer(std::nullopt)
    , active_renderer(nullptr)
    , pong_scene(SDL_FRect(0.f, 0.f, m_window.Width(), m_window.Height()))
{
}

AppState::AppState(Window&& window, OpenGL_Context&& gl_context)
    : AppState(std::move(window))
{
    this->gl_context.emplace(std::move(gl_context));
    active_renderer = &*this->gl_context;
}
AppState::AppState(Window&& window, Pong::SDL_Renderer&& sdl_renderer)
    : AppState(std::move(window))
{
    this->sdl_renderer.emplace(std::move(sdl_renderer));
    active_renderer = &*this->sdl_renderer;
}

AppState::~AppState()
{

}
void AppState::Iterate()
{
    active_renderer->Iterate(pong_scene);
}

Window& AppState::window()
{
    return m_window;
}
Renderer* AppState::renderer()
{
    return active_renderer;
}
