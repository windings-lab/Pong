#include "gl_context.h"

#include "SDL3/SDL_video.h"
#include "SDL3/SDL_opengl.h"

OpenGL_Context::OpenGL_Context(SDL_Window* window)
    : gl_context(SDL_GL_CreateContext(window))
{
    if (!gl_context) {
        throw std::runtime_error(SDL_GetError());
    }

    int width, height;
    SDL_GetWindowSizeInPixels(window, &width, &height);

    glViewport(0, 0, width, height);

    // Clear first frame buffer
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}

OpenGL_Context::~OpenGL_Context()
{
    if (gl_context) SDL_GL_DestroyContext(gl_context);
}

OpenGL_Context::OpenGL_Context(OpenGL_Context&& old) noexcept
    : gl_context(old.gl_context)
{
    old.gl_context = nullptr;
}

OpenGL_Context& OpenGL_Context::operator=(OpenGL_Context&& old) noexcept
{
    OpenGL_Context temp(std::move(old));
    swap(*this, temp);
    return *this;
}

SDL_GLContext OpenGL_Context::operator*() const
{
    return gl_context;
}
void OpenGL_Context::swap(OpenGL_Context& a, OpenGL_Context& b) noexcept
{
    using std::swap;
    swap(a.gl_context, b.gl_context);
}