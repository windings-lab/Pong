#pragma once
#include "game_object.h"

struct Paddle;

struct PlayerController : GameObject
{
    PlayerController();
    explicit PlayerController(Paddle* player);
    ~PlayerController() override;

    void Iterate(float dt) override;

    Paddle* player;
};