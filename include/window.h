#pragma once

class Window
{
public:
    explicit Window(SDL_Window* sdl_window);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) noexcept;
    Window& operator=(Window&&) noexcept;

    SDL_Window* operator*() const;

    [[nodiscard]] int Width() const;
    [[nodiscard]] int Height() const;

private:
    void swap(Window& a, Window& b) noexcept;

    SDL_Window* sdl_window;

    int width = 0;
    int height = 0;
};