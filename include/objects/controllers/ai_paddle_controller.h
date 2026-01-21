#pragma once
#include "ai_controller.h"

class AIPaddleController : public AIController
{
public:
    explicit AIPaddleController(class Paddle* bot, class Ball* ball);

    void Tick(float dt) override;

private:
    Paddle* m_controllable_paddle;
    Ball* m_ball;
};