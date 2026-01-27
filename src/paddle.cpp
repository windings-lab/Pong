#include "objects/game_objects/paddle.h"

#include "objects/game_objects/walls.h"
#include "sdl_renderer.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position)
    : GameObject(position)
{
    m_collider.w = width;
    m_collider.h = height;
    m_speed = 200.f;

    m_color = {255, 255, 255, 255};
}
Paddle::~Paddle()
{

}
void Paddle::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto walls = other->Cast<Walls>(); walls) {
        SDL_FRect bounds = walls->GetCollider();
        m_position.y = std::clamp(m_position.y, bounds.y, bounds.y + bounds.h - height);
    }
}
void Paddle::Draw(Pong::SDL::Renderer* renderer) const
{
    GameObject::Draw(renderer);

    renderer->DrawRect(SDL_FRect(m_position.x, m_position.y, width, height));
}
