#include "objects/object.h"

#include "levels/level.h"

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
void Object::SetLevel(Level* level)
{
    m_level = level;
}
SDL_FRect Object::GetLevelBounds() const
{
    return m_level->GetBounds();
}
Class* Object::GetClass()
{
    return StaticClass();
}