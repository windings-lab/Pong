#include "objects/game_objects/ball.h"

#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "sdl_renderer.h"

#include <cmath>

Ball::Ball() : Ball(nullptr) {}
Ball::Ball(SpawnPoint* spawn_point)
    : GameObject(spawn_point)
    , m_velocity(0.f, 0.f)
{
}
Ball::~Ball()
{
}
void Ball::Tick(float dt)
{
    GameObject::Tick(dt);
    Move(dt);
}
void Ball::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto paddle = dynamic_cast<Paddle*>(other); paddle) {
        // Push ball outside paddle first
        if (m_velocity.x > 0)
            position.x -= intersection.w;
        else
            position.x += intersection.w;

        // Compute hit position
        float paddleCenter = paddle->position.y + Paddle::height * 0.5f;
        float ballCenter   = position.y + height * 0.5f;

        float relativeY = ballCenter - paddleCenter;
        float normalized = relativeY / (Paddle::height * 0.5f);
        normalized = std::clamp(normalized, -1.0f, 1.0f);

        constexpr float MaxBounceAngle = 60.0f * (M_PI / 180.0f);
        float angle = 0.f;
        float threshold = 0.05f; // small tolerance for "center hit"
        if (std::abs(normalized) < threshold) {
            angle = RandomAngle(10.f, 20.f);
        } else {
            angle = normalized * MaxBounceAngle;
        }

        // Rebuild velocity
        float dir = (m_velocity.x > 0) ? -1.f : 1.f;

        m_velocity.x = dir * std::cos(angle) * speed;
        m_velocity.y = std::sin(angle) * speed;
    }
    if (auto wall = dynamic_cast<Walls*>(other); wall) {
        SDL_FRect bounds = wall->GetCollider();

        // Top wall
        if (position.y <= 0.f) {
            position.y = 0.f;
            m_velocity.y = -m_velocity.y;
        }

        // Bottom wall
        if (position.y + height > bounds.h) {
            position.y = bounds.h - height;
            m_velocity.y = -m_velocity.y;
        }

        // Left Paddle lost
        // Right paddle gains a score
        if (position.x <= 0.f) {
            Respawn();
        }

        // Right Paddle lost
        // Left paddle gains a score
        if (position.x + width >= bounds.w) {
            Respawn();
        }
    }

}
void Ball::Draw(Pong::SDL::Renderer* renderer) const
{
    GameObject::Draw(renderer);

    renderer->DrawRect(SDL_FRect(position.x, position.y, width, height));
}
SDL_FRect Ball::GetCollider()
{
    return SDL_FRect(position.x, position.y, width, height);
}
void Ball::Respawn()
{
    GameObject::Respawn();

    float angle = RandomFloat(-30.f, 30.f) * (M_PI / 180.f);

    m_velocity.x = RandomDirection() * std::cos(angle) * speed;
    m_velocity.y = std::sin(angle) * speed;
}
void Ball::Move(float dt)
{
    position.x += m_velocity.x * dt;
    position.y += m_velocity.y * dt;
}
