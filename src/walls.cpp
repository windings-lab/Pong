#include "objects/game_objects/walls.h"

Walls::Walls(SDL_FRect bounds)
    : m_bounds(bounds)
{
    visible = false;
}
Walls::~Walls()
{
}
SDL_FRect Walls::GetCollider()
{
    return SDL_FRect(position.x, position.y, m_bounds.w, m_bounds.h);
}