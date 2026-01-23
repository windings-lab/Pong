#pragma once

#include "controller.h"

class PaddlePlayerController : public Controller
{
public:
    DERIVED_STATIC_CLASS(Controller)

    explicit PaddlePlayerController(GameObject* player);

    void Tick(float dt) override;
};