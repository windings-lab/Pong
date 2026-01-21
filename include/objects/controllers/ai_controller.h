#pragma once

#include "controller.h"

class GameObject;

class AIController : public Controller
{
public:
    AIController();
    explicit AIController(GameObject* bot);
    ~AIController() override;

    void Tick(float dt) override;
};