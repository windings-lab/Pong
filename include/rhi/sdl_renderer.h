#pragma once
#include "rhi/renderer.h"

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

    protected:
        void BeforeUpdate() override;
        void AfterUpdate() override;

    private:
        void swap(Renderer& a, Renderer& b) noexcept override;

        ::SDL_Renderer* m_sdl_renderer;
    };
}