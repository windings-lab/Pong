#include "game_objects/paddle.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position) : GameObject(SDL_FRect(position.x, position.y, width, height)) {}
Paddle::~Paddle()
{

}
void Paddle::Iterate(float dt)
{
    GameObject::Iterate(dt);

    Move(dt);
}

void Paddle::Move(float dt)
{
    rect.y += speed * dt * movement_direction;
}
