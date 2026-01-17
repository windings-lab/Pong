#pragma once
#include "gl_context.h"

typedef struct SDL_Window SDL_Window;

class AppState
{
public:
    explicit AppState(SDL_Window* window, OpenGL_Context&& gl_context);

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

    AppState(AppState&&) noexcept = delete;
    AppState& operator=(AppState&&) noexcept = delete;

    ~AppState();

    [[nodiscard]] SDL_Window* Window() const;
    [[nodiscard]] OpenGL_Context& GLContext();

private:
    SDL_Window* window;
    OpenGL_Context gl_context;
};
