#include "objects/game_objects/walls.h"

Walls::Walls(SDL_FRect bounds)
{
    SetCollider(bounds.w, bounds.h);
    SetVisible(false);
}
Walls::~Walls()
{
}
