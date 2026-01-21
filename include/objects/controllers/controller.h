#pragma once
#include "objects/object.h"

class GameObject;
class Controller : public Object
{
public:
    Controller();
    explicit Controller(GameObject* game_object);

protected:
    GameObject* m_controllable;
};