#pragma once

#include <cstdint>

#include <SFML/System/Vector2.hpp>

namespace snake
{
struct SnakeSegment
{
    SnakeSegment(uint32_t x, uint32_t y) : position(x, y){};
    sf::Vector2i position;
};
} // namespace snake
