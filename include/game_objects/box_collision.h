#pragma once
#include "game_object.h"

struct BoxCollision : GameObject
{
    BoxCollision();
    explicit BoxCollision(SDL_FRect constraint);
    ~BoxCollision() override;
    void Iterate(float dt) override;
    void OnCollide(GameObject* other, SDL_FRect intersection) override;
};