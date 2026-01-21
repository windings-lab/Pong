#pragma once
#include "levels/pong_scene.h"
#include "window.h"

class Renderer;

class AppState
{
public:
    explicit AppState(Window&& window, std::unique_ptr<Renderer> renderer);

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

    std::unique_ptr<Renderer> m_renderer;

    PongScene m_pong_scene;
};
