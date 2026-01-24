#include "objects/game_objects/walls.h"

Walls::Walls(SDL_FRect bounds)
{
    m_collider = bounds;
    m_visible = false;
}
Walls::~Walls()
{
}
