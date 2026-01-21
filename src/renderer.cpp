#include "rhi/renderer.h"

#include "objects/game_objects/game_object.h"

Renderer::Renderer()
{

}
Renderer::~Renderer() = default;

void Renderer::Iterate(const std::vector<GameObject*>& game_objects)
{
    BeforeUpdate();
    Update(game_objects);
    AfterUpdate();
}

void Renderer::Update(const std::vector<GameObject*>& game_objects)
{
    for (auto game_object : game_objects) {
        game_object->Draw(this);
    }
}