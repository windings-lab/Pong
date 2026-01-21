#pragma once

#include "objects/object.h"

class SpawnPoint;
struct Renderer;

class GameObject : public Object
{
public:
    GameObject();
    explicit GameObject(SDL_FPoint);
    explicit GameObject(SpawnPoint*);
    explicit GameObject(SDL_FPoint, SpawnPoint*);
    ~GameObject() override;

    void Initialize() override;

    virtual void Respawn();

    virtual void ConsumeInput(int input);

    virtual void OnCollide(GameObject* other, SDL_FRect intersection);
    virtual void Draw(Renderer* renderer) const;

    virtual SDL_FRect GetCollider();

    SDL_FPoint position;
    bool visible;

protected:
    ObjectPointer<SpawnPoint> m_spawner;
};