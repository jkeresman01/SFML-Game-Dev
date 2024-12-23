#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace breakout
{

class Paddle
{
  public:
    Paddle();

    void update();
    void render(sf::RenderWindow &window) const;

    void moveLeft();
    void moveRight();

    void setPosition(float positionX, float positionY);

    sf::FloatRect getBounds() const { return m_paddle.getGlobalBounds(); }
    sf::Vector2f getPosition() const { return m_paddle.getPosition(); }

  private:
    sf::RectangleShape m_paddle;
    float m_speed;
};

} // namespace breakout
