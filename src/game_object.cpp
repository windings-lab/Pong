#include "game_objects/game_object.h"

GameObject::GameObject(::SDL_FRect rect)
    : rect(rect)
    , visible(true)
    , collidable(false)
{
}
GameObject::~GameObject() = default;
void GameObject::Iterate(float dt)
{

}
void GameObject::OnCollide(GameObject* other, SDL_FRect intersection)
{
}