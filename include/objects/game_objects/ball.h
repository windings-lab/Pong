#pragma once

#include "objects/game_objects/game_object.h"

class Ball : public GameObject
{
public:
    DERIVED_STATIC_CLASS(GameObject)

    Ball();
    ~Ball() override;
    void Initialize() override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;

    void Draw(Pong::SDL::Renderer* renderer) const override;

    void Respawn() override;

    constexpr static float width = 25.f;
    constexpr static float height = 25.f;
};