#pragma once
#include "player_controller.h"

class PaddlePlayerController : public PlayerController
{
public:
    explicit PaddlePlayerController(GameObject* player);

    void Tick(float dt) override;
};