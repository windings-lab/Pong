#include "app_state.h"

#include "SDL3/SDL_rect.h"
#include "objects/game_objects/game_object.h"
#include "rhi/gl_context.h"

const Uint64 AppState::m_frequency = SDL_GetPerformanceFrequency();

AppState::AppState(Window&& window, std::unique_ptr<Renderer> renderer)
    : m_last_time(SDL_GetPerformanceCounter())
    , m_window(std::move(window))
    , m_renderer(std::move(renderer))
    , m_pong_scene(SDL_FRect(0.f, 0.f, m_window.width(), m_window.height()))
{

}

AppState::~AppState()
{

}
void AppState::OnInitialize()
{
    for (auto object : m_pong_scene.Objects()) {
        object->Initialize();
    }
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
    TickObjects();
    ResolveCollisions();
    Render();
}
float AppState::CalculateDeltaTime()
{
    Uint64 current_time = SDL_GetPerformanceCounter();
    float dt = static_cast<float>(current_time - m_last_time) / m_frequency;
    m_last_time = current_time;

    return dt;
}
void AppState::TickObjects()
{
    float dt = CalculateDeltaTime();
    for (auto game_object : m_pong_scene.Objects()) {
        game_object->Tick(dt);
    }
}
void AppState::ResolveCollisions()
{
    auto& game_objects = m_pong_scene.GameObjects();

    for (size_t i = 0; i < game_objects.size(); ++i) {
        for (size_t j = i + 1; j < game_objects.size(); ++j) {
            GameObject* a = *game_objects[i];
            GameObject* b = *game_objects[j];

            SDL_FRect a_collider = a->GetCollider();
            SDL_FRect b_collider = b->GetCollider();

            SDL_FRect intersection;
            if (SDL_GetRectIntersectionFloat(&a_collider, &b_collider, &intersection)) {
                a->OnCollide(b, intersection);
                b->OnCollide(a, intersection);
            }
        }
    }
}
void AppState::Render()
{
    m_renderer->Iterate(m_pong_scene.GameObjects());
}
