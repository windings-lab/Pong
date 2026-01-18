#include "game_objects/pong_scene.h"

PongScene::PongScene(SDL_FRect constraint)
    : constraint(constraint)
{
    const float constraint_mid_y = constraint.h / 2.f - Paddle::height / 2.f;

    player.rect.y = constraint_mid_y;

    bot.rect.x = constraint.w - Paddle::width;
    bot.rect.y = constraint_mid_y;

    player_controller.player = &player;

    game_objects.push_back(&player);
    game_objects.push_back(&bot);
    game_objects.push_back(&player_controller);
}
