#include "rhi/renderer.h"

#include "objects/game_objects/game_object.h"

Renderer::Renderer()
{

}
Renderer::~Renderer() = default;

void Renderer::Iterate(const std::vector<ObjectPointer<GameObject>>& game_objects)
{
    BeforeUpdate();
    Update(game_objects);
    AfterUpdate();
}

void Renderer::Update(const std::vector<ObjectPointer<GameObject>>& game_objects)
{
    for (auto& game_object : game_objects) {
        if (!game_object->visible) continue;
        game_object->Draw(this);
    }
}