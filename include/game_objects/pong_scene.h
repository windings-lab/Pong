#pragma once
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

private:
    SDL_FRect constraint;
};
