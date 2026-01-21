#pragma once

#include "controller.h"

class PlayerController : public Controller
{
public:
    PlayerController();
    explicit PlayerController(GameObject* player);
    ~PlayerController() override;

    void Tick(float dt) override;
};