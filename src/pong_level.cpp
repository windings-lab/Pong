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

    m_player = gs->CreateObject<Paddle>(SDL_FPoint(0.f, paddle_middle_height));
    m_player->SetColor({0, 255, 0, 255});

    m_bot = gs->CreateObject<Paddle>(SDL_FPoint(m_bounds.w - Paddle::width, paddle_middle_height));
    m_bot->SetColor({255, 0, 0, 255});
    m_bot->SetSpeed(100.f);

    m_ball = gs->CreateObject<Ball>();
    m_ball->SubscribeToOnDestroy([this] {
        m_ball = nullptr;
    });
    SDL_FRect ball_collider = m_ball->GetCollider();
    m_ball_spawn_point = {
        m_bounds.w / 2.f - ball_collider.w / 2.f,
        m_bounds.h / 2.f - ball_collider.h / 2.f
    };
    m_ball->SubscribeToOnCollideEvent([this](GameObject* other, SDL_FRect intersection) {
        HandleBallCollision(other, intersection);
    });
    BallRespawn();

    gs->CreateObject<Walls>(m_bounds);
    gs->CreateObject<PaddlePlayerController>(m_player);

    auto ai_controller = gs->CreateObject<AIPaddleController>(m_bot);
    ai_controller->SetBall(m_ball);
    m_ball->SubscribeToOnDestroy([ai_controller] {
        ai_controller->SetBall(nullptr);
    });
}
void LPong::Scored(Paddle* player)
{
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
void LPong::HandleBallCollision(GameObject* other, SDL_FRect intersection)
{
    if (auto walls = other->Cast<Walls>(); walls) {
        SDL_FRect wall_bounds = walls->GetCollider();
        SDL_FPoint ball_position = m_ball->GetPosition();
        SDL_FRect ball_collider = m_ball->GetCollider();

        if (ball_position.x <= wall_bounds.x) {
            Scored(m_bot);
            BallRespawn();
        }

        if (ball_position.x + ball_collider.w >= wall_bounds.w + wall_bounds.x) {
            Scored(m_player);
            BallRespawn();
        }
    }
}
