#include "objects/controllers/ai_paddle_controller.h"

#include "objects/game_objects/ball.h"
#include "objects/game_objects/paddle.h"

AIPaddleController::AIPaddleController(Paddle* bot, Ball* ball)
    : AIController(static_cast<GameObject*>(bot))
    , m_controllable_paddle(bot)
    , m_ball(ball)
{
}
void AIPaddleController::Tick(float dt)
{
    AIController::Tick(dt);

    if (!m_controllable_paddle || !m_ball) return;

    float bot_y_middle = m_controllable_paddle->position.y + Paddle::height / 2.f;
    float ball_y_middle = m_ball->position.y + Ball::height / 2.f;

    int dir = 0;
    if (bot_y_middle < ball_y_middle) {
        dir = 1;
    }
    else if (bot_y_middle > ball_y_middle) {
        dir = -1;
    }

    m_controllable->ConsumeInput(dir);
}