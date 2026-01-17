#pragma once

typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Window SDL_Window;

namespace Pong
{
    class SDL_Renderer
    {
    public:
        explicit SDL_Renderer(SDL_Window* window, ::SDL_Renderer* sdl_renderer);
        ~SDL_Renderer();

        SDL_Renderer(const SDL_Renderer&) = delete;
        SDL_Renderer& operator=(const SDL_Renderer&) = delete;

        SDL_Renderer(SDL_Renderer&&) noexcept;
        SDL_Renderer& operator=(SDL_Renderer&&) noexcept;

        ::SDL_Renderer* operator*() const;

        void Iterate();

    private:
        void swap(SDL_Renderer& a, SDL_Renderer& b) noexcept;

        SDL_Window* window;
        ::SDL_Renderer* sdl_renderer;
    };
}