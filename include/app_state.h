#pragma once
#include "game_objects/pong_scene.h"
#include "rhi/gl_context.h"
#include "rhi/sdl_renderer.h"
#include "window.h"

#include <optional>

class AppState
{
public:
    explicit AppState(Window&& window, OpenGL_Context&& gl_context);
    explicit AppState(Window&& window, Pong::SDL_Renderer&& sdl_renderer);

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

    AppState(AppState&&) noexcept = delete;
    AppState& operator=(AppState&&) noexcept = delete;

    ~AppState();

    SDL_AppResult HandleEvent(SDL_Event* event);
    void Iterate();

    [[nodiscard]] Window& window();
    [[nodiscard]] Renderer* renderer();

private:
    AppState(Window&& window);

    const static Uint64 frequency;
    Uint64 last_time;

    Window m_window;

    std::optional<OpenGL_Context> gl_context;
    std::optional<Pong::SDL_Renderer> sdl_renderer;
    Renderer* active_renderer;

    PongScene pong_scene;
};
