#pragma once
#include "objects/object.h"

class Controller : public Object
{
public:
    Controller();
    explicit Controller(class GameObject* game_object);

protected:
    ObjectPointer<class GameObject> m_controllable;
};