#include "app_state.h"

#include <SDL3/SDL_video.h>

AppState::AppState(SDL_Window* window)
    : window(window)
    , gl_context(SDL_GL_CreateContext(window))
{
    if (!gl_context) {
        throw std::runtime_error(SDL_GetError());
    }

#ifdef __unix__
    // Clear first frame buffer
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
#endif
}

AppState::AppState(AppState&& old) noexcept
    : window(old.window)
    , gl_context(old.gl_context)
{
    old.window = nullptr;
    old.gl_context = nullptr;
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
    if (gl_context) SDL_GL_DestroyContext(gl_context);
}

SDL_Window* AppState::Window() const
{
    return window;
}
SDL_GLContext AppState::GLContext() const
{
    return gl_context;
}

void AppState::swap(AppState& a, AppState& b) noexcept
{
    using std::swap;
    swap(a.window, b.window);
    swap(a.gl_context, b.gl_context);
}
