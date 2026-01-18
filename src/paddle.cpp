#include "game_objects/paddle.h"

Paddle::Paddle() : Paddle(SDL_FPoint(0.f, 0.f)) {}
Paddle::Paddle(SDL_FPoint position) : GameObject(SDL_FRect(position.x, position.y, width, height)) {}
Paddle::~Paddle()
{

}