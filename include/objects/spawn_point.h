#pragma once

#include "object.h"

class SpawnPoint : public Object
{

public:
    explicit SpawnPoint();
    explicit SpawnPoint(SDL_FPoint spawn_position);

    SDL_FPoint spawn_position;

    DERIVED_STATIC_CLASS(Object)
};