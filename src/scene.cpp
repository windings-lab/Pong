#include "levels/scene.h"

#include "objects/game_objects/game_object.h"

Scene::Scene()
{
}
const std::vector<std::unique_ptr<Object>>& Scene::Objects() const
{
    return m_objects;
}
std::vector<GameObject*> Scene::GameObjects() const
{
    std::vector<GameObject*> game_objects;

    for (const auto& object : m_objects) {
        auto game_object = object->Cast<GameObject>();
        game_objects.push_back(game_object);
    }
    game_objects.shrink_to_fit();

    return game_objects;
}