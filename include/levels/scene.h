#pragma once

class GameObject;
class Object;

class Scene
{
public:
    Scene();

    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    Scene(const Scene&&) noexcept = delete;
    Scene& operator=(const Scene&&) noexcept = delete;

    std::vector<ObjectPointer<GameObject>>& GameObjects();
    std::vector<ObjectPointer<Object>>& Objects();

    const std::vector<ObjectPointer<GameObject>>& GameObjects() const;
    const std::vector<ObjectPointer<Object>>& Objects() const;

protected:
    std::vector<ObjectPointer<GameObject>> m_game_objects;
    std::vector<ObjectPointer<Object>> m_objects;
};