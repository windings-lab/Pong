#include "app_state.h"

#include "rhi/gl_context.h"
#include "SDL3/SDL_rect.h"

const Uint64 AppState::frequency = SDL_GetPerformanceFrequency();

AppState::AppState(Window&& window)
    : last_time(SDL_GetPerformanceCounter())
    , m_window(std::move(window))
    , gl_context(std::nullopt)
    , sdl_renderer(std::nullopt)
    , active_renderer(nullptr)
    , pong_scene(SDL_FRect(0.f, 0.f, m_window.Width(), m_window.Height()))
{
}

AppState::AppState(Window&& window, OpenGL_Context&& gl_context)
    : AppState(std::move(window))
{
    this->gl_context.emplace(std::move(gl_context));
    active_renderer = &*this->gl_context;
}
AppState::AppState(Window&& window, Pong::SDL_Renderer&& sdl_renderer)
    : AppState(std::move(window))
{
    this->sdl_renderer.emplace(std::move(sdl_renderer));
    active_renderer = &*this->sdl_renderer;
}

AppState::~AppState()
{

}
SDL_AppResult AppState::HandleEvent(SDL_Event* event)
{
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;

    default:
        break;
    }

    return SDL_APP_CONTINUE;
}
void AppState::Iterate()
{
    Uint64 current_time = SDL_GetPerformanceCounter();
    float dt = static_cast<float>(current_time - last_time) / frequency;
    last_time = current_time;

    for (auto game_object : pong_scene.game_objects) {
        game_object->Iterate(dt);
    }

    for (size_t i = 0; i < pong_scene.game_objects.size(); ++i) {
        for (size_t j = i + 1; j < pong_scene.game_objects.size(); ++j) {

            GameObject* a = pong_scene.game_objects[i];
            GameObject* b = pong_scene.game_objects[j];

            if (!a->collidable || !b->collidable)
                continue;

            SDL_FRect intersection;
            if (SDL_GetRectIntersectionFloat(&a->rect, &b->rect, &intersection)) {
                a->OnCollide(b, intersection);
                b->OnCollide(a, intersection);
            }
        }
    }

    active_renderer->Iterate(pong_scene);
}

Window& AppState::window()
{
    return m_window;
}
Renderer* AppState::renderer()
{
    return active_renderer;
}
