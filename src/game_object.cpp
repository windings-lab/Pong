#include "objects/game_objects/game_object.h"

#include "objects/spawn_point.h"

GameObject::GameObject()
    : GameObject(SDL_FPoint(0.f, 0.f))
{
}
GameObject::GameObject(SDL_FPoint position)
    : GameObject(position, nullptr)
{
}
GameObject::GameObject(SpawnPoint* spawn_point)
    : GameObject(SDL_FPoint(0.f, 0.f), spawn_point)
{
}
GameObject::GameObject(SDL_FPoint position, SpawnPoint* spawn_point)
    : position(position)
    , visible(true)
    , m_spawner(spawn_point)
{
}
GameObject::~GameObject() = default;
void GameObject::Initialize()
{
    Object::Initialize();

    Respawn();
}
void GameObject::Respawn()
{
    if (!m_spawner) return;

    position = m_spawner->spawn_position;
}

void GameObject::ConsumeInput(int input)
{
}
void GameObject::OnCollide(GameObject* other, SDL_FRect intersection)
{
}
void GameObject::Draw(Renderer* renderer) const
{
}
SDL_FRect GameObject::GetCollider()
{
    return SDL_FRect(position.x, position.y);
}
