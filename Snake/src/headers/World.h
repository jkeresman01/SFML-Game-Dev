#pragma once

#include "Apple.h"
#include "Snake.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
class World
{
  public:
    World(const sf::Vector2u &windowSize);
    ~World() = default;

    uint32_t getBlockSize() const { return m_blockSize; };
    void respwanApple();

    void update(Snake &snake);
    void render(sf::RenderWindow &window);

  private:
    bool isPlayerOutsideTheWorld(const Snake &snake);

  private:
    sf::Vector2f m_windowSize;
    sf::Vector2i m_appleCoordinates;
    Apple m_apple;
    sf::RectangleShape m_bounds[4];
    uint32_t m_blockSize;
};
} // namespace snake
