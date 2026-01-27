#include "objects/game_objects/game_object.h"

#include "../../../MSVC/BuildTools/VC/Tools/MSVC/14.50.35717/include/chrono"
#include "sdl_renderer.h"

GameObject::GameObject()
    : GameObject(SDL_FPoint(0.f, 0.f))
{
}
GameObject::GameObject(SDL_FPoint position)
    : m_position(position)
    , m_collider()
    , m_color()
    , m_visible(true)
    , m_speed(0.f)
    , m_direction()
{
}
GameObject::~GameObject() = default;

void GameObject::Tick(float dt)
{
    Object::Tick(dt);

    m_position.x += m_direction.x * dt * m_speed;
    m_position.y += m_direction.y * dt * m_speed;
}
void GameObject::Respawn()
{
}
void GameObject::OnCollide(GameObject* other, SDL_FRect intersection)
{
}
void GameObject::Draw(Pong::SDL::Renderer* renderer) const
{
    renderer->SetColor(m_color);
}
SDL_FRect GameObject::GetCollider()
{
    m_collider.x = m_position.x;
    m_collider.y = m_position.y;
    return m_collider;
}
void GameObject::SetPosition(SDL_FPoint value)
{
    m_position = value;
}
SDL_FPoint GameObject::GetPosition() const
{
    return m_position;
}
bool GameObject::IsVisible() const
{
    return m_visible;
}
void GameObject::SetColor(SDL_Color value)
{
    m_color = value;
}
void GameObject::SetDirection(SDL_FPoint value)
{
    m_direction = value;
}
void GameObject::SetSpeed(float value)
{
    m_speed = value;
}
