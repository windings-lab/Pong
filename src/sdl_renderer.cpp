#include "rhi/sdl_renderer.h"

#include "game_objects/pong_scene.h"

#include <utility>

namespace Pong
{
    SDL_Renderer::SDL_Renderer(::SDL_Renderer* sdl_renderer)
        : sdl_renderer(sdl_renderer)
    {
    }
    SDL_Renderer::~SDL_Renderer()
    {
        if (sdl_renderer) SDL_DestroyRenderer(sdl_renderer);
    }
    SDL_Renderer::SDL_Renderer(SDL_Renderer&& old) noexcept
        : sdl_renderer(std::exchange(old.sdl_renderer, nullptr))
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
        return sdl_renderer;
    }
    void SDL_Renderer::DrawRect(SDL_FRect rect)
    {
        SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(sdl_renderer, &rect);
    }
    void SDL_Renderer::Iterate(PongScene& pong_scene)
    {
        SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
        SDL_RenderClear(sdl_renderer);

        for (auto game_object : pong_scene.game_objects) {
            DrawRect(game_object->rect);
        }

        SDL_RenderPresent(sdl_renderer);
    }
    void SDL_Renderer::swap(Renderer& a, Renderer& b) noexcept
    {
        using std::swap;

        auto& a_casted = static_cast<SDL_Renderer&>(a);
        auto& b_casted = static_cast<SDL_Renderer&>(b);

        swap(a_casted.sdl_renderer, b_casted.sdl_renderer);
    }
} // namespace Pong