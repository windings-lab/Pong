#include "objects/controllers/player_controller.h"

#include "objects/game_objects/paddle.h"

PlayerController::PlayerController()
    : PlayerController(nullptr)
{
}
PlayerController::PlayerController(GameObject* player)
    : Controller(player)
{
}
PlayerController::~PlayerController()
{
}
void PlayerController::Tick(float dt)
{

}