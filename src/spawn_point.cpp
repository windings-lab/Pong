#include "objects/spawn_point.h"

SpawnPoint::SpawnPoint()
    : SpawnPoint(SDL_FPoint(0.f, 0.f))
{
}
SpawnPoint::SpawnPoint(SDL_FPoint spawn_position)
    : spawn_position(spawn_position)
{
}
