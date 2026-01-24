#pragma once

#include "controller.h"

class Ball;

class AIPaddleController : public Controller
{
public:
    DERIVED_STATIC_CLASS(Controller)

    explicit AIPaddleController(GameObject* bot);

    void Initialize() override;
    void Tick(float dt) override;

private:
    const Ball* m_ball;
};