#pragma once
#include "gl_context.h"
#include "sdl_renderer.h"

#include <optional>

typedef struct SDL_Window SDL_Window;

class AppState
{
public:
    explicit AppState(SDL_Window* window, OpenGL_Context&& gl_context);
    explicit AppState(SDL_Window* window, Pong::SDL_Renderer&& sdl_renderer);

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

    AppState(AppState&&) noexcept = delete;
    AppState& operator=(AppState&&) noexcept = delete;

    ~AppState();

    [[nodiscard]] SDL_Window* Window() const;
    [[nodiscard]] OpenGL_Context& GLContext();
    [[nodiscard]] Pong::SDL_Renderer& SDL_Renderer();

private:
    SDL_Window* window;
    std::optional<OpenGL_Context> gl_context;
    std::optional<Pong::SDL_Renderer> sdl_renderer;
};
