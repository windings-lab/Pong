#include "objects/game_objects/paddle.h"

#include "objects/game_objects/walls.h"
#include "rhi/renderer.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position)
    : GameObject(position)
{
}
Paddle::~Paddle()
{

}
void Paddle::SetMovementDirection(signed int value)
{
    m_movement_direction = value;
}
void Paddle::ConsumeInput(int input)
{
    GameObject::ConsumeInput(input);

    SetMovementDirection(input);
}
void Paddle::Tick(float dt)
{
    GameObject::Tick(dt);

    Move(dt);
}
void Paddle::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto walls = dynamic_cast<Walls*>(other); walls) {
        SDL_FRect bounds = walls->GetCollider();

        if (m_movement_direction == -1 && position.y <= bounds.y) {
            m_movement_direction = 0;
            position.y = 0.f;
        }

        if (m_movement_direction == 1 && position.y >= (bounds.y + bounds.h) - height) {
            m_movement_direction = 0;
            position.y = (bounds.y + bounds.h) - height;
        }
    }
}
void Paddle::Draw(Renderer* renderer) const
{
    GameObject::Draw(renderer);

    renderer->DrawRect(SDL_FRect(position.x, position.y, width, height));
}
SDL_FRect Paddle::GetCollider()
{
    return SDL_FRect(position.x, position.y, width, height);
}

void Paddle::Move(float dt)
{
    position.y += speed * dt * m_movement_direction;
}
