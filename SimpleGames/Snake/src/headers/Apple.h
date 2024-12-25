#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
class Apple
{
  public:
    Apple();

    void setPosition(const sf::Vector2i &position);
    void render(sf::RenderWindow &window);

  private:
    sf::CircleShape m_apple;
    sf::Vector2i m_coordinates;
    uint32_t m_size;
};
} // namespace snake
