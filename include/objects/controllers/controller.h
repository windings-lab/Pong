#pragma once
#include "objects/object.h"

class Controller : public Object
{
public:
    Controller();
    explicit Controller(class GameObject* game_object);

protected:
    GameObject* m_controllable;
};