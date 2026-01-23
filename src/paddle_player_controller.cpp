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
    int dir = 0;
    if (key_state[SDL_SCANCODE_UP]) dir = -1;
    if (key_state[SDL_SCANCODE_DOWN]) dir = 1;

    m_controllable->ConsumeInput(dir);
}