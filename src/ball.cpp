#include "game_objects/ball.h"

#include "game_objects/box_collision.h"
#include "game_objects/paddle.h"

#include <algorithm>
#include <cmath>

Ball::Ball() : Ball(SDL_FPoint(0.f, 0.f)) {}
Ball::Ball(SDL_FPoint position)
    : GameObject(SDL_FRect(position.x, position.y, width, height))
    , velocity(0.f, 0.f)
{
    collidable = true;
    visible = true;
}
Ball::~Ball()
{
}
void Ball::Iterate(float dt)
{
    GameObject::Iterate(dt);
    Move(dt);
}
void Ball::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto paddle = dynamic_cast<Paddle*>(other); paddle) {
        // Push ball outside paddle first
        if (velocity.x > 0)
            rect.x -= intersection.w;
        else
            rect.x += intersection.w;

        // Compute hit position
        float paddleCenter = paddle->rect.y + paddle->rect.h * 0.5f;
        float ballCenter   = rect.y + rect.h * 0.5f;

        float relativeY = ballCenter - paddleCenter;
        float normalized = relativeY / (paddle->rect.h * 0.5f);
        normalized = std::clamp(normalized, -1.0f, 1.0f);

        constexpr float MaxBounceAngle = 75.0f * (M_PI / 180.0f);
        float angle = normalized * MaxBounceAngle;

        // Rebuild velocity
        float dir = (velocity.x > 0) ? -1.f : 1.f;

        velocity.x = dir * std::cos(angle) * speed;
        velocity.y = std::sin(angle) * speed;
    }
    if (auto wall = dynamic_cast<BoxCollision*>(other); wall) {
        // Top wall
        if (rect.y <= 0.f) {
            rect.y = 0.f;
            velocity.y = -velocity.y;
        }

        // Bottom wall
        if (rect.y + rect.h > wall->rect.h) {
            rect.y = wall->rect.h - rect.h;
            velocity.y = -velocity.y;
        }

        // Left Paddle lost
        // Right paddle gains a score
        if (rect.x <= 0.f) {
            Spawn();
        }

        // Right Paddle lost
        // Left paddle gains a score
        if (rect.x + rect.w >= wall->rect.w) {
            Spawn();
        }
    }

}
void Ball::Move(float dt)
{
    rect.x += velocity.x * dt;
    rect.y += velocity.y * dt;
}
void Ball::Spawn()
{
    rect.x = spawn_point.x;
    rect.y = spawn_point.y;

    float angle = RandomFloat(-30.f, 30.f) * (M_PI / 180.f);

    velocity.x = RandomDirection() * std::cos(angle) * speed;
    velocity.y = std::sin(angle) * speed;
}