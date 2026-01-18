#include "game_objects/pong_scene.h"

PongScene::PongScene(SDL_FRect constraint)
{
    const float paddle_middle_height = constraint.h / 2.f - Paddle::height / 2.f;

    player.rect.y = paddle_middle_height;

    bot.rect.x = constraint.w - Paddle::width;
    bot.rect.y = paddle_middle_height;

    player_controller.player = &player;
    player.player_controller = &player_controller;

    const float ball_x_middle = constraint.w / 2.f - Ball::width / 2.f;
    const float ball_y_middle = constraint.h / 2.f - Ball::height / 2.f;

    ball.spawn_point.x = ball_x_middle;
    ball.spawn_point.y = ball_y_middle;
    ball.Spawn();

    this->constraint.rect = constraint;

    game_objects.push_back(&player);
    game_objects.push_back(&bot);
    game_objects.push_back(&player_controller);
    game_objects.push_back(&this->constraint);
    game_objects.push_back(&ball);
}
