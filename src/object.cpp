#include "objects/object.h"

Object::Object()
{
}
Object::~Object()
{
    if (OnDestroyedEvent)
        OnDestroyedEvent->Emit();
}
void Object::Tick(float dt)
{
}
void Object::SetLevel(Level* level)
{
    m_level = level;
}
const Level* Object::GetLevel() const
{
    return m_level;
}
void Object::SubscribeToOnDestroy(std::function<void()>&& callback) const
{
    if (!OnDestroyedEvent)
        OnDestroyedEvent = std::make_unique<Observer<>>();

    OnDestroyedEvent->Subscribe(std::move(callback));
}
Class* Object::GetClass()
{
    return StaticClass();
}