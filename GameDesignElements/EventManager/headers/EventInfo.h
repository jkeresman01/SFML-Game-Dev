#pragma once

#include <cstdint>

namespace sfmlgamedev
{
    struct EventInfo
    {
        EventInfo() : m_code(0) {};
        EventInfo(uint32_t event) : m_code(event){};

        union
        {
            uint32_t m_code;
        };
    };
}
