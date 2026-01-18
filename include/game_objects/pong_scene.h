#pragma once

#include "ball.h"
#include "box_collision.h"
#include "paddle.h"
#include "player_controller.h"

#include <vector>

struct Renderer;

class PongScene
{
public:
    explicit PongScene(SDL_FRect constraint);

    PongScene(const PongScene&) = delete;
    PongScene& operator=(const PongScene&) = delete;

    std::vector<GameObject*> game_objects;

    Paddle player;
    Paddle bot;
    PlayerController player_controller;
    Ball ball;

private:
    BoxCollision constraint;
};
