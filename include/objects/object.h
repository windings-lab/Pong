#pragma once

class Object
{
public:
    Object();
    virtual ~Object();

    virtual void Initialize();
    virtual void Tick(float dt);
};