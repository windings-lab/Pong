#include "levels/pong_scene.h"

#include "objects/controllers/ai_paddle_controller.h"
#include "objects/controllers/paddle_player_controller.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "objects/object_pointer.h"
#include "objects/spawn_point.h"

PongScene::PongScene(SDL_FRect constraint)
{
    const float paddle_middle_height = constraint.h / 2.f - Paddle::height / 2.f;

    auto player = CreateObject<Paddle>(SDL_FPoint(0.f, paddle_middle_height));
    auto bot = CreateObject<Paddle>(SDL_FPoint(constraint.w - Paddle::width, paddle_middle_height));
    bot->speed = 100.f;

    const float ball_x_middle = constraint.w / 2.f - Ball::width / 2.f;
    const float ball_y_middle = constraint.h / 2.f - Ball::height / 2.f;
    auto ball_spawner = CreateObject<SpawnPoint>(SDL_FPoint(ball_x_middle, ball_y_middle));

    auto ball = CreateObject<Ball>(*ball_spawner);
    auto walls = CreateObject<Walls>(constraint);
    auto player_controller = CreateObject<PaddlePlayerController>(*player);
    auto ai_controller = CreateObject<AIPaddleController>(*bot, *ball);
}

