#include "levels/pong_scene.h"

#include "objects/controllers/ai_paddle_controller.h"
#include "objects/controllers/paddle_player_controller.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "objects/spawn_point.h"

PongScene::PongScene(SDL_FRect constraint)
{
    const float paddle_middle_height = constraint.h / 2.f - Paddle::height / 2.f;

    auto player = CreateObject<Paddle>(SDL_FPoint(0.f, paddle_middle_height));
    auto bot = CreateObject<Paddle>(SDL_FPoint(constraint.w - Paddle::width, paddle_middle_height));
    bot->speed = 100.f;

    auto ball = CreateObject<Ball>();
    CreateObject<Walls>(constraint);
    CreateObject<PaddlePlayerController>(player);
    CreateObject<AIPaddleController>(bot, ball);
}
