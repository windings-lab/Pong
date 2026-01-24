#include "objects/game_objects/game_object.h"

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
    , m_velocity()
{
}
GameObject::~GameObject() = default;
void GameObject::Initialize()
{
    Object::Initialize();

    Respawn();
}
void GameObject::Tick(float dt)
{
    Object::Tick(dt);

    m_position.x += m_velocity.x * dt * m_speed;
    m_position.y += m_velocity.y * dt * m_speed;
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
SDL_FPoint GameObject::GetPosition() const
{
    return m_position;
}
bool GameObject::IsVisible() const
{
    return m_visible;
}
void GameObject::SetColor(SDL_Color color)
{
    m_color = color;
}
void GameObject::SetVelocity(SDL_FPoint velocity)
{
    m_velocity = velocity;
}
void GameObject::SetSpeed(float speed)
{
    m_speed = speed;
}
