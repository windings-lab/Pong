#include "game_objects/box_collision.h"
BoxCollision::BoxCollision()
    : BoxCollision(SDL_FRect(0.f, 0.f, 0.f, 0.f))
{
}
BoxCollision::BoxCollision(SDL_FRect constraint)
    : GameObject(constraint)
{
    visible = false;
    collidable = true;
}
BoxCollision::~BoxCollision()
{
}
void BoxCollision::Iterate(float dt)
{
    GameObject::Iterate(dt);
}
void BoxCollision::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);
}