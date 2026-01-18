#include "game_objects/game_object.h"

GameObject::GameObject(::SDL_FRect rect)
    : spawn_point(0.f, 0.f)
    , rect(rect)
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