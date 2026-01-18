#include "game_objects/pong_scene.h"

PongScene::PongScene()
    : player(SDL_FPoint(0.f, 0.f))
    , bot(SDL_FPoint(800 - 50.f, 0.f))
{
}
