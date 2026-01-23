#pragma once

#include "levels/pong_scene.h"
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

    void OnInitialize();
    SDL_AppResult HandleEvent(SDL_Event* event);
    void Iterate();

private:
    float CalculateDeltaTime();
    void TickObjects();
    void ResolveCollisions();
    void Render();

private:
    const static Uint64 m_frequency;
    Uint64 m_last_time;

    Window m_window;

    Pong::SDL::Renderer m_renderer;

    PongScene m_pong_scene;
};
