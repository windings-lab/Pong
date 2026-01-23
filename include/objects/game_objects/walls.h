#pragma once
#include "game_object.h"

class Walls : public GameObject
{
public:
    DERIVED_STATIC_CLASS(GameObject)

    explicit Walls(SDL_FRect);
    ~Walls() override;

    SDL_FRect GetCollider() override;

private:
    SDL_FRect m_bounds;
};