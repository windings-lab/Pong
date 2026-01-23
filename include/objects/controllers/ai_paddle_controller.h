#pragma once

#include "controller.h"

class AIPaddleController : public Controller
{
public:
    DERIVED_STATIC_CLASS(Controller)

    explicit AIPaddleController(class Paddle* bot, class Ball* ball);

    void Tick(float dt) override;

private:
    Paddle* m_controllable_paddle;
    Ball* m_ball;
};