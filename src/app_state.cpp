#include "app_state.h"

#include "SDL3/SDL_video.h"

#include "gl_context.h"

AppState::AppState(SDL_Window* window, OpenGL_Context&& gl_context)
    : window(window)
    , gl_context(gl_context)
{
}

AppState::AppState(AppState&& old) noexcept
    : window(old.window)
    , gl_context(old.gl_context)
{
    old.window = nullptr;
}

AppState& AppState::operator=(AppState&& old) noexcept
{
    AppState temp(std::move(old));
    swap(*this, temp);
    return *this;
}

AppState::~AppState()
{
    if (window) SDL_DestroyWindow(window);
}

SDL_Window* AppState::Window() const
{
    return window;
}
SDL_GLContext AppState::GLContext() const
{
    return *gl_context;
}

void AppState::swap(AppState& a, AppState& b) noexcept
{
    using std::swap;
    swap(a.window, b.window);
    swap(a.gl_context, b.gl_context);
}
