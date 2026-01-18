#include "window.h"

#include <utility>

Window::Window(SDL_Window* sdl_window)
    : sdl_window(sdl_window)
{
    SDL_GetWindowSizeInPixels(this->sdl_window, &width, &height);
}

Window::~Window()
{
    if (sdl_window) SDL_DestroyWindow(sdl_window);
}
Window::Window(Window&& old) noexcept
    : sdl_window(std::exchange(old.sdl_window, nullptr))
    , width(old.width)
    , height(old.height)
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
    return sdl_window;
}
int Window::Width() const
{
    return width;
}
int Window::Height() const
{
    return height;
}
void Window::swap(Window& a, Window& b) noexcept
{
    using std::swap;
    swap(a.sdl_window, a.sdl_window);
    swap(a.width, a.width);
    swap(a.height, a.height);
}