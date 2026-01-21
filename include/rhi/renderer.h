#pragma once

struct GameObject;

struct Renderer
{
    Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) noexcept = default;
    Renderer& operator=(Renderer&&) noexcept = default;

    virtual ~Renderer() = 0;

    void Iterate(const std::vector<ObjectPointer<GameObject>>& game_objects);

    virtual void DrawRect(SDL_FRect) = 0;

protected:
    virtual void BeforeUpdate() = 0;
    virtual void AfterUpdate() = 0;

    virtual void swap(Renderer& a, Renderer& b) noexcept = 0;

private:
    void Update(const std::vector<ObjectPointer<GameObject>>& game_objects);
};