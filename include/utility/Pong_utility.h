#pragma once

#include <random>


inline std::mt19937& Rng()
{
    static std::mt19937 rng{ std::random_device{}() };
    return rng;
}
inline float RandomFloat(float min, float max)
{
    std::uniform_real_distribution dist(min, max);
    return dist(Rng());
}
inline float RandomDirection()
{
    std::uniform_int_distribution dist(0, 1);
    return dist(Rng()) == 0 ? -1.f : 1.f;
}
inline float RandomAngle(float minDegrees, float maxDegrees)
{
    std::uniform_real_distribution dist(minDegrees, maxDegrees);
    return dist(Rng()) * (std::numbers::pi / 180.f);
}
