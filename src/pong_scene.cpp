#include "levels/pong_scene.h"

#include <algorithm>

PongScene::PongScene(SDL_FRect constraint)
    : ball(&ball_spawner)
    , walls(constraint)
    , player_controller(&player)
    , ai_controller(&bot, &ball)
{
    const float paddle_middle_height = constraint.h / 2.f - Paddle::height / 2.f;

    player.position.y = paddle_middle_height;

    bot.position.x = constraint.w - Paddle::width;
    bot.position.y = paddle_middle_height;
    bot.speed = 100.f;

    const float ball_x_middle = constraint.w / 2.f - Ball::width / 2.f;
    const float ball_y_middle = constraint.h / 2.f - Ball::height / 2.f;

    ball_spawner.spawn_position.x = ball_x_middle;
    ball_spawner.spawn_position.y = ball_y_middle;

    m_game_objects.push_back(&player);
    m_game_objects.push_back(&bot);
    m_game_objects.push_back(&walls);
    m_game_objects.push_back(&ball);

    m_objects.reserve(m_game_objects.size());
    std::ranges::transform(m_game_objects,
                           std::back_inserter(m_objects),
                           [](GameObject* go) { return static_cast<Object*>(go); });
    m_objects.push_back(&ai_controller);
    m_objects.push_back(&player_controller);
}
const std::vector<GameObject*>& PongScene::GameObjects() const
{
    return m_game_objects;
}
const std::vector<Object*>& PongScene::Objects() const
{
    return m_objects;
}
