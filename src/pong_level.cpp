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
    player->SetColor({0, 255, 0, 255});

    auto bot = gs->CreateObject<Paddle>(SDL_FPoint(m_bounds.w - Paddle::width, paddle_middle_height));
    bot->SetColor({255, 0, 0, 255});
    bot->SetSpeed(100.f);

    m_ball = gs->CreateObject<Ball>();
    m_ball->SubscribeToOnDestroy([this] {
        m_ball = nullptr;
    });
    SDL_FRect ball_collider = m_ball->GetCollider();
    m_ball_spawn_point = {
        m_bounds.w / 2.f - ball_collider.w / 2.f,
        m_bounds.h / 2.f - ball_collider.h / 2.f
    };
    BallRespawn();

    gs->CreateObject<Walls>(m_bounds);
    gs->CreateObject<PaddlePlayerController>(player);

    auto ai_controller = gs->CreateObject<AIPaddleController>(bot);
    ai_controller->SetBall(m_ball);
    m_ball->SubscribeToOnDestroy([ai_controller] {
        ai_controller->SetBall(nullptr);
    });
}

void LPong::BallRespawn()
{
    m_ball->SetPosition(m_ball_spawn_point);

    // Randomize direction on spawn
    float angle = RandomFloat(-30.f, 30.f) * (std::numbers::pi / 180.f);
    m_ball->SetDirection({
        RandomDirection() * std::cos(angle),
        std::sin(angle)
    });
}
