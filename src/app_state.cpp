#include "app_state.h"

#include "SDL3/SDL_rect.h"
#include "levels/pong_level.h"
#include "objects/game_objects/game_object.h"

AppState::AppState(Window&& window, Pong::SDL::Renderer&& renderer)
    : m_window(std::move(window))
    , m_renderer(std::move(renderer))
    , m_game_state(std::make_unique<LPong>(SDL_FRect(0.f, 0.f, m_window.width(), m_window.height())))
{

}

AppState::~AppState()
{

}
void AppState::Initialize()
{
    m_game_state.Initialize();
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
    m_game_state.Iterate();
    ResolveCollisions();
    Render();
}

void AppState::ResolveCollisions()
{
    auto& objects = m_game_state.Objects();

    for (size_t i = 0; i < objects.size(); ++i) {
        auto a = objects[i]->Cast<GameObject>();
        if (!a) continue;

        for (size_t j = i + 1; j < objects.size(); ++j) {
            auto b = objects[j]->Cast<GameObject>();
            if (!b) continue;

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
    m_renderer.Iterate(m_game_state.Objects());
}
