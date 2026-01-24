#pragma once
#include "level.h"

class LPong : public Level
{
public:
    explicit LPong(SDL_FRect bounds);

    void Populate(GameState*) override;
};
