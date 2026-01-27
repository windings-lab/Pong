#pragma once

#include "level.h"

class Paddle;
class GameObject;
class Ball;

class LPong : public Level
{
public:
    explicit LPong(SDL_FRect bounds);

    void Populate(GameState*) override;

private:
    void Scored(Paddle* player);
    void BallRespawn();
    void HandleBallCollision(GameObject* other, SDL_FRect intersection);

    Paddle* m_player = nullptr;
    Paddle* m_bot = nullptr;

    Ball* m_ball = nullptr;
    SDL_FPoint m_ball_spawn_point{};
};
