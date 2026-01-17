#pragma once

typedef struct SDL_Window SDL_Window;
typedef struct SDL_GLContextState *SDL_GLContext;

class OpenGL_Context
{
public:
    explicit OpenGL_Context(SDL_Window* window);
    ~OpenGL_Context();

    OpenGL_Context(const OpenGL_Context&) = delete;
    OpenGL_Context& operator=(const OpenGL_Context&) = delete;

    OpenGL_Context(OpenGL_Context&&) noexcept;
    OpenGL_Context& operator=(OpenGL_Context&&) noexcept;

    SDL_GLContext operator*() const;

    void Iterate();

private:
    void swap(OpenGL_Context& a, OpenGL_Context& b) noexcept;

    SDL_Window* window;
    SDL_GLContext gl_context;
};