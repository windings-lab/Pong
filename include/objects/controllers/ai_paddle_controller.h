#pragma once
#include "ai_controller.h"

class AIPaddleController : public AIController
{
public:
    explicit AIPaddleController(class Paddle* bot, class Ball* ball);

    void Tick(float dt) override;

private:
    ObjectPointer<class Paddle> m_controllable_paddle;
    ObjectPointer<class Ball> m_ball;
};