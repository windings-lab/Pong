#pragma once

#include "objects/object.h"

class GameObject;

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

    template<typename T, typename... Args>
    ObjectPointer<T> CreateObject(Args&&... args) {
        static_assert(std::is_base_of_v<Object, T>, "T must derive from Object");

        // Add object in-place to the owning vector
        m_objects.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        T& ref = static_cast<T&>(*m_objects.back());
        m_objects_cached.emplace_back(&ref);

        // If it’s a GameObject, also add a handle to m_game_objects
        if constexpr (std::is_base_of_v<GameObject, T>) {
            m_game_objects.emplace_back(&ref);
        }

        return ObjectPointer<T>{&ref}; // return handle
    }

protected:
    std::vector<ObjectPointer<GameObject>> m_game_objects;
    std::vector<ObjectPointer<Object>> m_objects_cached;
    std::vector<std::unique_ptr<Object>> m_objects;
};