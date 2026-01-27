#pragma once
#include "level.h"

class Ball;

class LPong : public Level
{
public:
    explicit LPong(SDL_FRect bounds);

    void Populate(GameState*) override;

    void BallRespawn();

private:
    Ball* m_ball = nullptr;
    SDL_FPoint m_ball_spawn_point{};
};
