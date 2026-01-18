#pragma once

class PongScene;

struct Renderer
{
    Renderer() = default;
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) noexcept = default;
    Renderer& operator=(Renderer&&) noexcept = default;

    virtual ~Renderer() = 0;

    virtual void DrawRect(SDL_FRect) = 0;

    virtual void Iterate(PongScene&) = 0;

protected:
    virtual void swap(Renderer& a, Renderer& b) noexcept = 0;
};