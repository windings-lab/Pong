#pragma once
#include "game_object.h"

struct Paddle : GameObject
{
    Paddle();
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;

    void Iterate(float dt) override;

    void Move(float dt);

    static constexpr float width = 50.f;
    static constexpr float height = 100.f;

    float speed = 100.f;
    signed int movement_direction : 2 = 0;
};