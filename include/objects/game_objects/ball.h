#pragma once

#include "objects/game_objects/game_object.h"

class SpawnPoint;
class Ball : public GameObject
{
public:
    Ball();
    explicit Ball(SpawnPoint*);

    ~Ball() override;
    void Tick(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;

    void Draw(Renderer* renderer) override;

    SDL_FRect GetCollider() override;

    void Respawn() override;

    constexpr static float width = 25;
    constexpr static float height = 25.f;

    float speed = 250.f;

private:
    void Move(float dt);

    SDL_FPoint m_velocity;
};