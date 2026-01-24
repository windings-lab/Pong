#include "levels/pong_level.h"

#include "objects/controllers/ai_paddle_controller.h"
#include "objects/controllers/paddle_player_controller.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "objects/game_state.h"

LPong::LPong(SDL_FRect bounds)
    : Level(bounds)
{

}

void LPong::Populate(GameState* gs)
{
    const float paddle_middle_height = m_bounds.h / 2.f - Paddle::height / 2.f;

    auto player = gs->CreateObject<Paddle>(SDL_FPoint(0.f, paddle_middle_height));
    auto bot = gs->CreateObject<Paddle>(SDL_FPoint(m_bounds.w - Paddle::width, paddle_middle_height));
    bot->SetSpeed(100.f);

    auto ball = gs->CreateObject<Ball>();
    gs->CreateObject<Walls>(m_bounds);
    gs->CreateObject<PaddlePlayerController>(player);
    gs->CreateObject<AIPaddleController>(bot, ball);
}
