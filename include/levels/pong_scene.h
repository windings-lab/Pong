#pragma once

#include "objects/controllers/ai_paddle_controller.h"
#include "objects/controllers/paddle_player_controller.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "objects/spawn_point.h"

#include "scene.h"

class PongScene : public Scene
{
public:
    explicit PongScene(SDL_FRect constraint);

    Paddle player;
    Paddle bot;
    SpawnPoint ball_spawner;
    Ball ball;
    Walls walls;
    PaddlePlayerController player_controller;
    AIPaddleController ai_controller;
};
