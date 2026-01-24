#pragma once

#include "objects/game_objects/game_object.h"

class Paddle : public GameObject
{
public:
    DERIVED_STATIC_CLASS(GameObject)

    Paddle();
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;

    /* GameObject Overrides */
    void OnCollide(GameObject* other, SDL_FRect intersection) override;
    void Draw(Pong::SDL::Renderer* renderer) const override;
    /* GameObject Overrides */

    constexpr static float width = 50.f;
    constexpr static float height = 100.f;
};