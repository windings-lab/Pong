#pragma once

class Object
{
public:
    Object();
    virtual ~Object();

    virtual void Initialize();
    virtual void Tick(float dt);

    std::weak_ptr<bool> GetAliveFlag();

private:
    std::shared_ptr<bool> alive;
};