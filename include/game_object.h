#pragma once

struct Renderer;


struct GameObject
{
    explicit GameObject(SDL_FRect);
    virtual ~GameObject();

    SDL_FRect rect;
};