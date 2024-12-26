#pragma once

#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace sfmlgamedev
{
    struct EventDetails
    {
        EventDetails(const std::string &bindName) : m_name(bindName) { clear(); };

        std::string m_name;
        sf::Vector2i m_size;
        sf::Uint32 m_textEntered;
        sf::Vector2i m_mouse;
        uint32_t m_mouseWheelDelta;
        uint32_t m_keyCode;

        void clear()
        {
            m_size = sf::Vector2i(0, 0);
            m_textEntered = 0;
            m_mouse = sf::Vector2i(0, 0);
            m_mouseWheelDelta = 0;
            m_keyCode = -1;
        }
    };
}
