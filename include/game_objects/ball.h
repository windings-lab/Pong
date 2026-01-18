#pragma once
#include "game_object.h"

struct Ball : GameObject
{
    Ball();
    explicit Ball(SDL_FPoint);

    ~Ball() override;
    void Iterate(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;

    void Move(float dt);
    void Spawn();

    static constexpr float width = 25.f;
    static constexpr float height = 25.f;
    static constexpr float speed = 100.f;

    SDL_FPoint velocity;
};