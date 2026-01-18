#pragma once
#include "game_object.h"

struct Paddle : GameObject
{
    Paddle();
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;

    static constexpr float width = 50.f;
    static constexpr float height = 100.f;
};