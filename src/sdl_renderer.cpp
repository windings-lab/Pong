#include "rhi/sdl_renderer.h"

namespace Pong
{
    SDL_Renderer::SDL_Renderer(::SDL_Renderer* sdl_renderer)
        : m_sdl_renderer(sdl_renderer)
    {
    }
    SDL_Renderer::~SDL_Renderer()
    {
        if (m_sdl_renderer) SDL_DestroyRenderer(m_sdl_renderer);
    }
    SDL_Renderer::SDL_Renderer(SDL_Renderer&& old) noexcept
        : m_sdl_renderer(std::exchange(old.m_sdl_renderer, nullptr))
    {
    }
    SDL_Renderer& SDL_Renderer::operator=(SDL_Renderer&& old) noexcept
    {
        SDL_Renderer temp(std::move(old));
        swap(*this, temp);
        return *this;
    }
    ::SDL_Renderer* SDL_Renderer::operator*() const
    {
        return m_sdl_renderer;
    }
    void SDL_Renderer::DrawRect(SDL_FRect rect)
    {
        SDL_SetRenderDrawColor(m_sdl_renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(m_sdl_renderer, &rect);
    }
    void SDL_Renderer::BeforeUpdate()
    {
        SDL_SetRenderDrawColor(m_sdl_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_sdl_renderer);
    }
    void SDL_Renderer::AfterUpdate()
    {
        SDL_RenderPresent(m_sdl_renderer);
    }
    void SDL_Renderer::swap(Renderer& a, Renderer& b) noexcept
    {
        using std::swap;

        auto& a_casted = static_cast<SDL_Renderer&>(a);
        auto& b_casted = static_cast<SDL_Renderer&>(b);

        swap(a_casted.m_sdl_renderer, b_casted.m_sdl_renderer);
    }
} // namespace Pong