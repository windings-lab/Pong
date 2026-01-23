#pragma once

#include "objects/game_objects/game_object.h"

class Paddle : public GameObject
{
public:
    Paddle();
    explicit Paddle(SDL_FPoint);
    ~Paddle() override;

    void SetMovementDirection(signed int value);

    constexpr static float width = 50.f;
    constexpr static float height = 100.f;

    float speed = 200.f;

public:
    /* GameObject Overrides */
    void ConsumeInput(int input) override;
    void Tick(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;
    void Draw(Pong::SDL::Renderer* renderer) const override;

    SDL_FRect GetCollider() override;
    /* GameObject Overrides */

private:
    void Move(float dt);

private:
    signed int m_movement_direction : 2 = 0;
};