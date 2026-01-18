#pragma once
#include "rhi/renderer.h"

typedef struct SDL_Window SDL_Window;
typedef struct SDL_GLContextState *SDL_GLContext;

class OpenGL_Context : public Renderer
{
public:
    explicit OpenGL_Context(SDL_Window* window);
    ~OpenGL_Context() override;

    OpenGL_Context(OpenGL_Context&&) noexcept;
    OpenGL_Context& operator=(OpenGL_Context&&) noexcept;

    SDL_GLContext operator*() const;

    void DrawRect(SDL_FRect rect) override;

    void Iterate(PongScene&) override;

private:
    void swap(Renderer& a, Renderer& b) noexcept override;

    SDL_Window* window;
    SDL_GLContext gl_context;
};