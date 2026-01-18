#pragma once

struct Renderer;


struct GameObject
{
    explicit GameObject(::SDL_FRect);
    virtual ~GameObject();

    virtual void Iterate(float dt);
    virtual void OnCollide(GameObject* other, SDL_FRect intersection);

    SDL_FPoint spawn_point;
    SDL_FRect rect;
    bool visible;
    bool collidable;
};