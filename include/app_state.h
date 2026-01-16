#pragma once

typedef struct SDL_Window SDL_Window;

class AppState
{
public:
    explicit AppState(SDL_Window* window);
    ~AppState();

private:
    SDL_Window *window;
};
