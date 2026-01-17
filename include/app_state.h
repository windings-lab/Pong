#pragma once

typedef struct SDL_Window SDL_Window;
typedef struct SDL_GLContextState *SDL_GLContext;

struct OpenGL_Context;

class AppState
{
public:
    explicit AppState(SDL_Window* window, OpenGL_Context&& gl_context);

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

    AppState(AppState&&) noexcept;
    AppState& operator=(AppState&&) noexcept;

    ~AppState();

    [[nodiscard]] SDL_Window* Window() const;
    [[nodiscard]] SDL_GLContext GLContext() const;

private:
    void swap(AppState& a, AppState& b) noexcept;

    SDL_Window* window;
    OpenGL_Context& gl_context;
};
