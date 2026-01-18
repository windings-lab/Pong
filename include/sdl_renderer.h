#pragma once
#include "renderer.h"

typedef struct SDL_Renderer SDL_Renderer;

namespace Pong
{
    class SDL_Renderer : public Renderer
    {
    public:
        explicit SDL_Renderer(::SDL_Renderer* sdl_renderer);
        ~SDL_Renderer() override;

        SDL_Renderer(SDL_Renderer&&) noexcept;
        SDL_Renderer& operator=(SDL_Renderer&&) noexcept;

        ::SDL_Renderer* operator*() const;

        void DrawRect(SDL_FRect rect) override;

        void Iterate(PongScene&) override;

    private:
        void swap(Renderer& a, Renderer& b) noexcept override;

        ::SDL_Renderer* sdl_renderer;
    };
}