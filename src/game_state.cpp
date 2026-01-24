#include "objects/game_state.h"

#include "levels/level.h"

const Uint64 GameState::m_frequency = SDL_GetPerformanceFrequency();

GameState::GameState(std::unique_ptr<Level> level)
    : m_last_time(SDL_GetPerformanceCounter())
    , m_level(std::move(level))
{
}
const std::vector<std::unique_ptr<Object>>& GameState::Objects() const
{
    return m_objects;
}

void GameState::Initialize()
{
    m_level->Populate(this);

    for (auto& object : m_objects) {
        object->SetLevel(m_level.get());
        object->Initialize();
    }
}
void GameState::Iterate()
{
    TickObjects();
}
float GameState::CalculateDeltaTime()
{
    Uint64 current_time = SDL_GetPerformanceCounter();
    float dt = static_cast<float>(current_time - m_last_time) / m_frequency;
    m_last_time = current_time;

    return dt;
}
void GameState::TickObjects()
{
    float dt = CalculateDeltaTime();
    for (auto& game_object : m_objects) {
        game_object->Tick(dt);
    }
}
