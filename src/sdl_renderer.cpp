#include "sdl_renderer.h"

#include "objects/game_objects/game_object.h"

namespace Pong::SDL
{
    Renderer::Renderer(SDL_Renderer* sdl_renderer)
        : m_sdl_renderer(sdl_renderer)
    {
    }
    Renderer::~Renderer()
    {
        if (m_sdl_renderer) SDL_DestroyRenderer(m_sdl_renderer);
    }
    Renderer::Renderer(Renderer&& old) noexcept
        : m_sdl_renderer(std::exchange(old.m_sdl_renderer, nullptr))
    {
    }
    Renderer& Renderer::operator=(Renderer&& old) noexcept
    {
        Renderer temp(std::move(old));
        swap(*this, temp);
        return *this;
    }
    SDL_Renderer* Renderer::operator*() const
    {
        return m_sdl_renderer;
    }
    void Renderer::DrawRect(SDL_FRect rect)
    {
        SDL_SetRenderDrawColor(m_sdl_renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(m_sdl_renderer, &rect);
    }
    void Renderer::BeforeUpdate()
    {
        SDL_SetRenderDrawColor(m_sdl_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_sdl_renderer);
    }
    void Renderer::AfterUpdate()
    {
        SDL_RenderPresent(m_sdl_renderer);
    }
    void Renderer::swap(Renderer& a, Renderer& b) noexcept
    {
        using std::swap;

        auto& a_casted = static_cast<Renderer&>(a);
        auto& b_casted = static_cast<Renderer&>(b);

        swap(a_casted.m_sdl_renderer, b_casted.m_sdl_renderer);
    }
    void Renderer::Iterate(const std::vector<GameObject*>& game_objects)
    {
        BeforeUpdate();
        Update(game_objects);
        AfterUpdate();
    }
    void Renderer::Update(const std::vector<GameObject*>& game_objects)
    {
        for (auto game_object : game_objects) {
            if (!game_object->visible) continue;
            game_object->Draw(this);
        }
    }
} // namespace Pong