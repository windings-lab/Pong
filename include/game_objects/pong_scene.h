#pragma once
#include "paddle.h"

struct Renderer;

class PongScene
{
public:
    explicit PongScene(SDL_FRect constraint);

    PongScene(const PongScene&) = delete;
    PongScene& operator=(const PongScene&) = delete;

    Paddle player;
    Paddle bot;

private:
    SDL_FRect constraint;
};
