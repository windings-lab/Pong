#include "objects/game_objects/ball.h"

#include "levels/level.h"
#include "objects/game_objects/paddle.h"
#include "objects/game_objects/walls.h"
#include "sdl_renderer.h"

#include <cmath>

Ball::Ball()
{
    m_collider.w = width;
    m_collider.h = height;

    m_speed = 250.f;

    m_color = {255, 255, 0, 255};
}
Ball::~Ball()
{
}

void Ball::OnCollide(GameObject* other, SDL_FRect intersection)
{
    GameObject::OnCollide(other, intersection);

    if (auto paddle = dynamic_cast<Paddle*>(other); paddle) {
        // Push ball outside paddle first
        if (m_direction.x > 0)
            m_position.x -= intersection.w;
        else
            m_position.x += intersection.w;

        // Compute hit position
        float paddleCenter = paddle->GetPosition().y + Paddle::height * 0.5f;
        float ballCenter   = m_position.y + height * 0.5f;

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

        // Rebuild velocity
        float dir = (m_direction.x > 0) ? -1.f : 1.f;

        m_direction.x = dir * std::cos(angle);
        m_direction.y = std::sin(angle);
    }
    if (auto wall = dynamic_cast<Walls*>(other); wall) {
        SDL_FRect bounds = wall->GetCollider();

        // Top wall
        if (m_position.y <= 0.f) {
            m_position.y = 0.f;
            m_direction.y = -m_direction.y;
        }

        // Bottom wall
        if (m_position.y + height > bounds.h) {
            m_position.y = bounds.h - height;
            m_direction.y = -m_direction.y;
        }

        // Left Paddle lost
        // Right paddle gains a score
        if (m_position.x <= 0.f) {
            Respawn();
        }

        // Right Paddle lost
        // Left paddle gains a score
        if (m_position.x + width >= bounds.w) {
            Respawn();
        }
    }

}
void Ball::Draw(Pong::SDL::Renderer* renderer) const
{
    GameObject::Draw(renderer);

    renderer->DrawRect(SDL_FRect(m_position.x, m_position.y, width, height));
}
void Ball::Respawn()
{
    GameObject::Respawn();

    float angle = RandomFloat(-30.f, 30.f) * (std::numbers::pi / 180.f);

    m_direction.x = RandomDirection() * std::cos(angle);
    m_direction.y = std::sin(angle);
}
