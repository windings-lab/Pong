#pragma once
#include "paddle.h"

struct Renderer;

class PongScene
{
public:
    PongScene();

    PongScene(const PongScene&) = delete;
    PongScene& operator=(const PongScene&) = delete;

    Paddle player;
    Paddle bot;
};
