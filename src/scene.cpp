#include "levels/scene.h"

Scene::Scene()
{
}
std::vector<ObjectPointer<GameObject>>& Scene::GameObjects()
{
    return m_game_objects;
}
std::vector<ObjectPointer<Object>>& Scene::Objects()
{
    return m_objects_cached;
}
const std::vector<ObjectPointer<GameObject>>& Scene::GameObjects() const
{
    return m_game_objects;
}
const std::vector<ObjectPointer<Object>>& Scene::Objects() const
{
    return m_objects_cached;
}