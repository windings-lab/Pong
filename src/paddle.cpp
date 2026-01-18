#include "game_objects/paddle.h"

#include "game_objects/box_collision.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position)
    : GameObject(SDL_FRect(position.x, position.y, width, height))
    , player_controller(nullptr)
{
    collidable = true;
}
Paddle::~Paddle()
{

}
void Paddle::Iterate(float dt)
{
    GameObject::Iterate(dt);

    Move(dt);
}
void Paddle::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto box_collision = dynamic_cast<BoxCollision*>(other); box_collision) {
        if (movement_direction == -1 && intersection.y <= 0) {
            movement_direction = 0;
            rect.y = 0.f;
        }

        if (movement_direction == 1 && intersection.y >= box_collision->rect.h - rect.h) {
            movement_direction = 0;
            rect.y = box_collision->rect.h - rect.h;
        }
    }
}

void Paddle::Move(float dt)
{
    rect.y += speed * dt * movement_direction;
}
