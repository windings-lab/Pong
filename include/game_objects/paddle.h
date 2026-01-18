#pragma once
#include "game_object.h"

struct PlayerController;

struct Paddle : GameObject
{
    Paddle();
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;

    void Iterate(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;

    void Move(float dt);

    static constexpr float width = 50.f;
    static constexpr float height = 100.f;

    float speed = 200.f;
    signed int movement_direction : 2 = 0;
    PlayerController* player_controller;
};