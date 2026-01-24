#pragma once

#include "objects/object.h"

class Level;

class GameState
{
public:
    explicit GameState(std::unique_ptr<Level> level);

    GameState(const GameState&) = delete;
    GameState& operator=(const GameState&) = delete;

    GameState(const GameState&&) noexcept = delete;
    GameState& operator=(const GameState&&) noexcept = delete;

    const std::vector<std::unique_ptr<Object>>& Objects() const;

    template<typename T, typename... Args, typename = std::enable_if_t<std::is_base_of_v<Object, T>>>
    T* CreateObject(Args&&... args) {
        m_objects.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
        T* ptr = static_cast<T*>(m_objects.back().get());

        return ptr;
    }

    void Initialize();
    void Iterate();

private:
    float CalculateDeltaTime();
    void TickObjects();

    const static Uint64 m_frequency;
    Uint64 m_last_time;

    std::vector<std::unique_ptr<Object>> m_objects;
    std::unique_ptr<Level> m_level;
};