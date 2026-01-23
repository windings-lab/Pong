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

    const std::vector<std::unique_ptr<Object>>& Objects() const;
    std::vector<GameObject*>                    GameObjects() const;

    template<typename T, typename... Args, typename = std::enable_if_t<std::is_base_of_v<Object, T>>>
    T* CreateObject(Args&&... args) {
        m_objects.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        T* ptr = static_cast<T*>(m_objects.back().get());

        return ptr;
    }

protected:
    std::vector<std::unique_ptr<Object>> m_objects;
};