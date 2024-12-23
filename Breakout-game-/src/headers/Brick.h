#pragma once

#include <SFML/Graphics.hpp>

namespace breakout
{

class Brick
{
  public:
    Brick(float positionX, float positionY);

    void render(sf::RenderWindow &window) const;

    sf::FloatRect getBounds() const { return m_brick.getGlobalBounds(); }

  private:
    sf::RectangleShape m_brick;
};

} // namespace breakout
