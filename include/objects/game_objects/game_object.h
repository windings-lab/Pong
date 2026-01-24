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

    virtual void Respawn();

    virtual void ConsumeInput(int input);

    virtual void OnCollide(GameObject* other, SDL_FRect intersection);
    virtual void Draw(Pong::SDL::Renderer* renderer) const;

    virtual SDL_FRect GetCollider();

    SDL_FPoint position;
    bool visible;
};