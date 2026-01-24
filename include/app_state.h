#pragma once

#include "objects/game_state.h"
#include "sdl_renderer.h"
#include "window.h"

class Renderer;

class AppState
{
public:
    explicit AppState(Window&& window, Pong::SDL::Renderer&& renderer);

    AppState(const AppState&) = delete;
    AppState& operator=(const AppState&) = delete;

    AppState(AppState&&) noexcept = delete;
    AppState& operator=(AppState&&) noexcept = delete;

    ~AppState();

    void Initialize();
    SDL_AppResult HandleEvent(SDL_Event* event);
    void Iterate();

private:
    void ResolveCollisions();
    void Render();

    Window m_window;
    Pong::SDL::Renderer m_renderer;

    GameState m_game_state;
};
