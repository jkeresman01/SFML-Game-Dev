#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
class World
{
  public:
    World();
    ~World();

    uint32_t getBlockSize() const { return m_blockSize; };
    void respwanApple();

    void update();
    void render(sf::RenderWindow &window);

  private:
    sf::Vector2i m_appleCoordinates;
    sf::CircleShape m_apple;
    sf::RectangleShape m_bounds[4];
    uint32_t m_blockSize;
};
} // namespace snake
