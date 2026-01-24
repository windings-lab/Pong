#include "levels/level.h"


Level::Level(SDL_FRect bounds)
    : m_bounds(bounds)
{
}
SDL_FRect Level::GetBounds() const
{
    return m_bounds;
}