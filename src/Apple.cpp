#include "headers/Apple.h"

namespace snake
{
Apple::Apple() : m_size(16), m_coordinates(sf::Vector2i(0.0f, 0.0f))
{
    m_apple.setRadius(m_size / 2.0f);
    m_apple.setFillColor(sf::Color::Red);
}

void Apple::setPosition(const sf::Vector2i position)
{
    double positionX = position.x * m_size;
    double positionY = position.y * m_size;

    m_apple.setPosition(positionX, positionY);
}

void Apple::render(sf::RenderWindow &window)
{
    window.draw(m_apple);
}
} // namespace snake
