#include "objects/game_objects/game_object.h"

#include "objects/spawn_point.h"

GameObject::GameObject()
    : GameObject(SDL_FPoint(0.f, 0.f))
{
}
GameObject::GameObject(SDL_FPoint position)
    : position(position)
    , visible(true)
{
}
GameObject::~GameObject() = default;
void GameObject::Initialize()
{
    Object::Initialize();

    OnRespawn();
}
void GameObject::OnRespawn()
{
}

void GameObject::ConsumeInput(int input)
{
}
void GameObject::OnCollide(GameObject* other, SDL_FRect intersection)
{
}
void GameObject::Draw(Pong::SDL::Renderer* renderer) const
{
}
SDL_FRect GameObject::GetCollider()
{
    return SDL_FRect(position.x, position.y);
}
