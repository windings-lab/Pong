#pragma once

#include "controller.h"

class Ball;

class AIPaddleController : public Controller
{
public:
    DERIVED_STATIC_CLASS(Controller)

    explicit AIPaddleController(GameObject* bot);

    void Tick(float dt) override;

    void SetBall(Ball*);

private:
    const Ball* m_ball;
};