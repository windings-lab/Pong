#include "window.h"

#include <utility>

Window::Window(SDL_Window* sdl_window)
    : m_sdl_window(sdl_window)
{
    SDL_GetWindowSizeInPixels(this->m_sdl_window, &m_width, &m_height);
}

Window::~Window()
{
    if (m_sdl_window) SDL_DestroyWindow(m_sdl_window);
}
Window::Window(Window&& old) noexcept
    : m_sdl_window(std::exchange(old.m_sdl_window, nullptr))
    , m_width(old.m_width)
    , m_height(old.m_height)
{

}
Window& Window::operator=(Window&& old) noexcept
{
    Window temp(std::move(old));
    swap(*this, temp);
    return *this;
}

SDL_Window* Window::operator*() const
{
    return m_sdl_window;
}
int Window::width() const
{
    return m_width;
}
int Window::height() const
{
    return m_height;
}
void Window::swap(Window& a, Window& b) noexcept
{
    using std::swap;
    swap(a.m_sdl_window, a.m_sdl_window);
    swap(a.m_width, a.m_width);
    swap(a.m_height, a.m_height);
}