#pragma once
#include "game_objects/pong_scene.h"
#include "rhi/gl_context.h"
#include "rhi/sdl_renderer.h"

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

    void Iterate();

    [[nodiscard]] SDL_Window* Window() const;
    [[nodiscard]] Renderer* renderer();

private:
    AppState(SDL_Window* window);

    SDL_Window* window;

    std::optional<OpenGL_Context> gl_context;
    std::optional<Pong::SDL_Renderer> sdl_renderer;

    Renderer* active_renderer;

    PongScene pong_scene;
};
