#include "objects/controllers/ai_paddle_controller.h"

#include "levels/pong_level.h"
#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"

AIPaddleController::AIPaddleController(GameObject* bot)
    : Controller(bot)
    , m_ball(nullptr)
{
}
void AIPaddleController::Initialize()
{
    Controller::Initialize();

    m_ball = static_cast<const LPong*>(GetLevel())->GetBall();
    m_ball->SubscribeToOnDestroy([this] {
        m_ball = nullptr;
    });
}

void AIPaddleController::Tick(float dt)
{
    Controller::Tick(dt);

    if (!m_ball || !m_controllable) return;

    float bot_y_middle = m_controllable->GetPosition().y + Paddle::height / 2.f;
    float ball_y_middle = m_ball->GetPosition().y + Ball::height / 2.f;

    int dir = static_cast<int>(std::copysign(1.0f, ball_y_middle - bot_y_middle) * (ball_y_middle != bot_y_middle));

    m_controllable->SetDirection(SDL_FPoint(0.f, dir));
}
