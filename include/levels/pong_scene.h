#pragma once

#include "objects/controllers/ai_paddle_controller.h"
#include "objects/controllers/paddle_player_controller.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "objects/spawn_point.h"

class PongScene
{
public:
    explicit PongScene(SDL_FRect constraint);

    PongScene(const PongScene&) = delete;
    PongScene& operator=(const PongScene&) = delete;

    const std::vector<GameObject*>& GameObjects() const;
    const std::vector<Object*>& Objects() const;

    Paddle player;
    Paddle bot;
    SpawnPoint ball_spawner;
    Ball ball;
    Walls walls;
    PaddlePlayerController player_controller;
    AIPaddleController ai_controller;

private:
    std::vector<GameObject*> m_game_objects;
    std::vector<Object*> m_objects;
};
