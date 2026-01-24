#pragma once

#include "objects/game_objects/game_object.h"

class Ball : public GameObject
{
public:
    DERIVED_STATIC_CLASS(GameObject)

    ~Ball() override;
    void Initialize() override;
    void Tick(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;

    void Draw(Pong::SDL::Renderer* renderer) const override;

    SDL_FRect GetCollider() override;

    void Respawn() override;

    constexpr static float width = 25;
    constexpr static float height = 25.f;

    float speed = 250.f;

private:
    void Move(float dt);

    SDL_FPoint m_velocity{0.f, 0.f};
};