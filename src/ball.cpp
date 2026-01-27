#include "objects/game_objects/ball.h"

#include "levels/level.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "sdl_renderer.h"

#include <cmath>

Ball::Ball()
{
    SetCollider(width, height);
    SetSpeed(250.f);
    SetColor({255, 255, 0, 255});
}
Ball::~Ball()
{
}

void Ball::OnCollide(GameObject* other, SDL_FRect intersection)
{
    SDL_FPoint direction = GetDirection();
    SDL_FPoint position = GetPosition();

    if (auto paddle = dynamic_cast<Paddle*>(other); paddle) {
        // Push ball outside paddle first
        SDL_FRect paddleBounds = paddle->GetCollider();

        position.x = direction.x > 0.f ? paddleBounds.x - width : paddleBounds.x + paddleBounds.w;

        // Compute hit position
        float paddleCenter = paddle->GetPosition().y + Paddle::height * 0.5f;
        float ballCenter   = position.y + height * 0.5f;

        float relativeY = ballCenter - paddleCenter;
        float normalized = relativeY / (Paddle::height * 0.5f);
        normalized = std::clamp(normalized, -1.0f, 1.0f);

        constexpr float MaxBounceAngle = 60.0f * (std::numbers::pi / 180.0f);
        float angle = 0.f;
        float threshold = 0.05f; // small tolerance for "center hit"
        if (std::abs(normalized) < threshold) {
            angle = RandomAngle(10.f, 20.f);
        } else {
            angle = normalized * MaxBounceAngle;
        }

        // Rebuild direction
        float dir = -std::copysignf(1.f, direction.x);
        direction.x = dir * std::cos(angle);
        direction.y = std::sin(angle);

        SetPosition(position);
        SetDirection(direction);
    }
    if (auto wall = dynamic_cast<Walls*>(other); wall) {
        SDL_FRect bounds = wall->GetCollider();

        // Top wall
        if (position.y < bounds.y) {
            position.y = bounds.y;
            direction.y *= -1.f;

            SetPosition(position);
            SetDirection(direction);
        }

        // Bottom wall
        if (position.y + height > bounds.h + bounds.y) {
            position.y = bounds.h - height;
            direction.y *= -1.f;

            SetPosition(position);
            SetDirection(direction);
        }
    }

    GameObject::OnCollide(other, intersection);
}
void Ball::Draw(Pong::SDL::Renderer* renderer) const
{
    GameObject::Draw(renderer);

    SDL_FPoint position = GetPosition();

    renderer->DrawRect(SDL_FRect(position.x, position.y, width, height));
}
