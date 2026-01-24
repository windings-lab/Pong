#include "objects/controllers/controller.h"

#include "objects/game_objects/game_object.h"

Controller::Controller()
    : Controller(nullptr)
{
}
Controller::Controller(GameObject* game_object)
    : m_controllable(game_object)
{
    m_controllable->SubscribeToOnDestroy(std::bind(&Controller::OnControllableDestroyed, this));
}
void Controller::Tick(float dt)
{
    Object::Tick(dt);
}
void Controller::OnControllableDestroyed()
{
    m_controllable = nullptr;
}