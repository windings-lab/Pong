#include "objects/controllers/paddle_player_controller.h"

#include "objects/game_objects/game_object.h"
PaddlePlayerController::PaddlePlayerController(GameObject* player)
    : Controller(player)
{
}
void PaddlePlayerController::Tick(float dt)
{
    Controller::Tick(dt);

    if (!m_controllable) return;

    const bool* key_state = SDL_GetKeyboardState(nullptr);
    float dir = 0.f;
    if (key_state[SDL_SCANCODE_UP]) dir = -1.f;
    if (key_state[SDL_SCANCODE_DOWN]) dir = 1.f;

    m_controllable->SetVelocity(SDL_FPoint(0.f, dir));
}