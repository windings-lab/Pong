#include "paddle.h"

Paddle::Paddle(SDL_FPoint position)
    : GameObject(SDL_FRect(position.x, position.y, 50.f, 100.f))
{
}
Paddle::~Paddle()
{

}