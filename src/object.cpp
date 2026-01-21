#include "objects/object.h"

Object::Object()
    : alive(std::make_shared<bool>(true))
{

}
Object::~Object()
{
    *alive = false;
}
void Object::Initialize()
{
}
void Object::Tick(float dt)
{
}
std::weak_ptr<bool> Object::GetAliveFlag()
{
    return alive;
}