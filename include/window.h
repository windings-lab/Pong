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

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

private:
    void swap(Window& a, Window& b) noexcept;

    SDL_Window* m_sdl_window;

    int m_width;
    int m_height;
};