#include "rhi/gl_context.h"

#include "SDL3/SDL_opengl.h"
#include "SDL3/SDL_video.h"

OpenGL_Context::OpenGL_Context(SDL_Window* window)
    : window(window)
    , gl_context(SDL_GL_CreateContext(window))
{
    if (!gl_context) {
        throw std::runtime_error(SDL_GetError());
    }

    int width, height;
    SDL_GetWindowSizeInPixels(window, &width, &height);

    glViewport(0, 0, width, height);

    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

OpenGL_Context::~OpenGL_Context()
{
    if (gl_context) SDL_GL_DestroyContext(gl_context);
}

OpenGL_Context::OpenGL_Context(OpenGL_Context&& old) noexcept
    : window(old.window)
    , gl_context(old.gl_context)
{
    old.window = nullptr;
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
void OpenGL_Context::DrawRect(SDL_FRect rect)
{
    throw std::runtime_error("Not implemented");
}
void OpenGL_Context::Iterate(PongScene&)
{
    SDL_GL_SwapWindow(window);
}
void OpenGL_Context::swap(Renderer& a, Renderer& b) noexcept
{
    using std::swap;

    auto& a_casted = static_cast<OpenGL_Context&>(a);
    auto& b_casted = static_cast<OpenGL_Context&>(b);

    swap(a_casted.gl_context, b_casted.gl_context);
    swap(a_casted.window, b_casted.window);
}