#pragma once

#include <random>

inline float RandomFloat(float min, float max)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution dist(min, max);
    return dist(rng);
}

inline float RandomDirection()
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution dist(0, 1);
    return dist(rng) == 0 ? -1.f : 1.f;
}

inline float RandomAngle(float minDegrees, float maxDegrees)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<float> dist(minDegrees, maxDegrees);
    return dist(rng) * (M_PI / 180.f); // convert to radians
}