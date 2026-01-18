#include "game_objects/player_controller.h"

#include "game_objects/paddle.h"

PlayerController::PlayerController()
    : PlayerController(nullptr)
{
}
PlayerController::PlayerController(Paddle* player)
    : GameObject(SDL_FRect(0.f, 0.f, 0.f, 0.f))
    , player(player)
{
    visible = false;
}
PlayerController::~PlayerController()
{
}
void PlayerController::Iterate(float dt)
{
    GameObject::Iterate(dt);

    if (!player) return;

    const bool* key_state = SDL_GetKeyboardState(nullptr);
    int dir = 0;
    if (key_state[SDL_SCANCODE_UP]) dir = -1;
    if (key_state[SDL_SCANCODE_DOWN]) dir = 1;
    player->movement_direction = dir;
}