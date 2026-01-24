#pragma once
#include "level.h"

class Ball;

class LPong : public Level
{
public:
    explicit LPong(SDL_FRect bounds);

    void Populate(GameState*) override;

    const Ball* GetBall() const;

private:
    Ball* m_ball = nullptr;
};
