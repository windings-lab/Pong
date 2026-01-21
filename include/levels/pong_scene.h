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

    std::vector<ObjectPointer<GameObject>>& GameObjects();
    std::vector<ObjectPointer<Object>>& Objects();

    const std::vector<ObjectPointer<GameObject>>& GameObjects() const;
    const std::vector<ObjectPointer<Object>>& Objects() const;

    Paddle player;
    Paddle bot;
    SpawnPoint ball_spawner;
    Ball ball;
    Walls walls;
    PaddlePlayerController player_controller;
    AIPaddleController ai_controller;

private:
    std::vector<ObjectPointer<GameObject>> m_game_objects;
    std::vector<ObjectPointer<Object>> m_objects;
};
