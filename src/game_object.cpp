#include "game_object.h"

GameObject::GameObject(SDL_FRect rect)
    : rect(rect)
{
}
GameObject::~GameObject() = default;