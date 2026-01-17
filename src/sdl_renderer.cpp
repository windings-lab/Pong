#include "sdl_renderer.h"

#include <SDL3/SDL.h>

#include <utility>

namespace Pong
{
    SDL_Renderer::SDL_Renderer(SDL_Window* window, ::SDL_Renderer* sdl_renderer)
        : window(window), sdl_renderer(sdl_renderer)
    {
    }
    SDL_Renderer::~SDL_Renderer()
    {
        if (sdl_renderer) SDL_DestroyRenderer(sdl_renderer);
    }
    SDL_Renderer::SDL_Renderer(SDL_Renderer&& old) noexcept
        : window(std::exchange(old.window, nullptr))
        , sdl_renderer(std::exchange(old.sdl_renderer, nullptr))
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
    void SDL_Renderer::Iterate()
    {
        SDL_RenderClear(sdl_renderer);
        SDL_RenderPresent(sdl_renderer);
    }
    void SDL_Renderer::swap(SDL_Renderer& a, SDL_Renderer& b) noexcept
    {
        using std::swap;
        swap(a.sdl_renderer, b.sdl_renderer);
        swap(a.window, b.window);
    }
} // namespace Pong