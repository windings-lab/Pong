#include "objects/controllers/ai_controller.h"

AIController::AIController() : AIController(nullptr){}
AIController::AIController(GameObject* bot)
    : Controller(bot)
{
}

AIController::~AIController()
{
}

void AIController::Tick(float dt)
{

}