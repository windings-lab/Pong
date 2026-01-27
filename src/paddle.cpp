#include "objects/game_objects/paddle.h"

#include "objects/game_objects/walls.h"
#include "sdl_renderer.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position)
    : GameObject(position)
{
    SetCollider(width, height);
    SetSpeed(200.f);
    SetColor({255, 255, 255, 255});
}
Paddle::~Paddle()
{

}
void Paddle::OnCollide(GameObject* other, SDL_FRect intersection)
{
    if (auto walls = other->Cast<Walls>(); walls) {
        SDL_FRect wall_bounds = walls->GetCollider();
        SDL_FPoint position = GetPosition();

        position.y = std::clamp(position.y, wall_bounds.y, wall_bounds.y + wall_bounds.h - height);
        SetPosition(position);
    }

    GameObject::OnCollide(other, intersection);
}
void Paddle::Draw(Pong::SDL::Renderer* renderer) const
{
    GameObject::Draw(renderer);

    SDL_FPoint position = GetPosition();

    renderer->DrawRect(SDL_FRect(position.x, position.y, width, height));
}
