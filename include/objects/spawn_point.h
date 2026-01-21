#pragma once

#include "object.h"

class GameObject;
class SpawnPoint : public Object
{
public:
    explicit SpawnPoint();
    explicit SpawnPoint(SDL_FPoint spawn_position);

    SDL_FPoint spawn_position;
};