#pragma once
#include "objects/object.h"

class Controller : public Object
{
public:
    DERIVED_STATIC_CLASS(Object)

    Controller();
    explicit Controller(class GameObject* game_object);

    void Tick(float dt) override;

private:
    void OnControllableDestroyed();

protected:
    GameObject* m_controllable;
};