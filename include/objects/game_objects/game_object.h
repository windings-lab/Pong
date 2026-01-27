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

    void Tick(float dt) override;

    virtual void OnCollide(GameObject* other, SDL_FRect intersection);
    virtual void Draw(Pong::SDL::Renderer* renderer) const;

    SDL_FRect GetCollider();
    void SetCollider(float width, float height);
    void SubscribeToOnCollideEvent(std::function<void(GameObject*, SDL_FRect)>&& callback);

    void SetPosition(SDL_FPoint);
    SDL_FPoint GetPosition() const;

    bool IsVisible() const;
    void SetVisible(bool);

    void SetColor(SDL_Color);

    SDL_FPoint GetDirection() const;
    void SetDirection(SDL_FPoint);

    void SetSpeed(float);

private:
    SDL_FPoint m_position;
    SDL_FRect m_collider;

    SDL_Color m_color;
    bool m_visible;

    float m_speed;
    SDL_FPoint m_direction;

    Observer<GameObject*, SDL_FRect> OnCollideEvent;
};