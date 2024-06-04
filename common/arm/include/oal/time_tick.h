#pragma once

#include <stdint.h>
#include <chrono>

class TimeTick
{
public:
    static uint64_t Us()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock ::now().time_since_epoch()).count();
    }
    static uint64_t Ms()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock ::now().time_since_epoch()).count();
    }
    static uint64_t SystemMs()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }
};