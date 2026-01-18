#pragma once

struct Renderer;


struct GameObject
{
    explicit GameObject(::SDL_FRect);
    virtual ~GameObject();

    virtual void Iterate(float dt);

    SDL_FRect rect;
    bool visible;
};