#include "objects/controllers/controller.h"
Controller::Controller()
    : Controller(nullptr)
{
}
Controller::Controller(GameObject* game_object)
    : m_controllable(game_object)
{
}