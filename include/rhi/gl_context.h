#pragma once
#include "rhi/renderer.h"

class OpenGL_Context : public Renderer
{
public:
    explicit OpenGL_Context(SDL_Window* window);
    ~OpenGL_Context() override;

    OpenGL_Context(OpenGL_Context&&) noexcept;
    OpenGL_Context& operator=(OpenGL_Context&&) noexcept;

    SDL_GLContext operator*() const;

    void DrawRect(SDL_FRect rect) override;

private:
    void swap(Renderer& a, Renderer& b) noexcept override;

protected:
  void BeforeUpdate() override;
  void AfterUpdate() override;

private:
  SDL_Window* m_window;
    SDL_GLContext m_gl_context;
};