#include "game_objects/game_object.h"

GameObject::GameObject(::SDL_FRect rect)
    : rect(rect)
    , visible(true)
{
}
GameObject::~GameObject() = default;
void GameObject::Iterate(float dt)
{

}