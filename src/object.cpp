#include "objects/object.h"

Object::Object()
{
}
Object::~Object()
{

}
void Object::Initialize()
{
}
void Object::Tick(float dt)
{
}
Class* Object::GetClass()
{
    return StaticClass();
}