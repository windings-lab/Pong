#pragma once
#include "game_object.h"

struct Paddle : GameObject
{
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;
};