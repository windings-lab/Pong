#pragma once
#include "game_object.h"

struct Paddle;
struct Ball;
struct AIController : GameObject
{
    AIController();
    AIController(Paddle* bot, Ball* ball);
    ~AIController() override;
    void Iterate(float dt) override;

    Paddle* bot;
    Ball* ball;
};