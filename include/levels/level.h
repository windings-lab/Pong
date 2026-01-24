#pragma once

class GameState;

class Level
{
public:
    explicit Level(SDL_FRect bounds);
    virtual ~Level() = default;

    virtual void Populate(GameState*) = 0;

    SDL_FRect GetBounds() const;

protected:
    SDL_FRect m_bounds;
};