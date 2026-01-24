#pragma once

class Object;

namespace Pong::SDL
{
    class Renderer
    {
    public:
        explicit Renderer(SDL_Renderer* sdl_renderer);
        ~Renderer();

        Renderer(Renderer&&) noexcept;
        Renderer& operator=(Renderer&&) noexcept;

        SDL_Renderer* operator*() const;

        void Iterate(const std::vector<std::unique_ptr<Object>>& objects);

        void DrawRect(SDL_FRect rect);

    private:
        void BeginFrame();
        void Draw(const std::vector<std::unique_ptr<Object>>& objects);
        void EndFrame();

        void swap(Renderer& a, Renderer& b) noexcept;

        SDL_Renderer* m_sdl_renderer;
    };
}