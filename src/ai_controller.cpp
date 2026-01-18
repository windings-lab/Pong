#include "game_objects/ai_controller.h"

#include "game_objects/ball.h"
#include "game_objects/paddle.h"

AIController::AIController() : AIController(nullptr, nullptr){}
AIController::AIController(Paddle* bot, Ball* ball)
    : GameObject(SDL_FRect(0.f, 0.f, 0.f, 0.f))
    , bot(bot)
    , ball(ball)
{
    collidable = false;
    visible = false;
}

AIController::~AIController()
{
}

void AIController::Iterate(float dt)
{
    GameObject::Iterate(dt);

    float bot_y_middle = bot->rect.y + bot->rect.h / 2.f;
    float ball_y_middle = ball->rect.y + ball->rect.h / 2.f;

    if (bot_y_middle < ball_y_middle) {
        bot->movement_direction = 1;
    }
    else if (bot_y_middle > ball_y_middle) {
        bot->movement_direction = -1;
    }
    else {
        bot->movement_direction = 0;
    }
}