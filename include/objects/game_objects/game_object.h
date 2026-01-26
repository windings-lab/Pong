#pragma once

#include "objects/object.h"

class SpawnPoint;

namespace Pong::SDL
{
    class Renderer;
}


class GameObject : public Object
{
public:
    DERIVED_STATIC_CLASS(Object)

    GameObject();
    explicit GameObject(SDL_FPoint);
    ~GameObject() override;

    void Initialize() override;
    void Tick(float dt) override;

    virtual void Respawn();

    virtual void OnCollide(GameObject* other, SDL_FRect intersection);
    virtual void Draw(Pong::SDL::Renderer* renderer) const;

    SDL_FRect GetCollider();
    SDL_FPoint GetPosition() const;

    bool IsVisible() const;
    void SetColor(SDL_Color);

    void SetDirection(SDL_FPoint);
    void SetSpeed(float);

protected:
    SDL_FPoint m_position;
    SDL_FRect m_collider;

    SDL_Color m_color;
    bool m_visible;

    float m_speed;
    SDL_FPoint m_direction;
};