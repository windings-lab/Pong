#pragma once

#include "controller.h"

class PaddlePlayerController : public Controller
{
public:
    explicit PaddlePlayerController(GameObject* player);

    void Tick(float dt) override;
};