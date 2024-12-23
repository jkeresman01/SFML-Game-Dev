#include "headers/Brick.h"

#include "headers/Colors.h"
#include "headers/GameConstants.h"

namespace breakout
{

Brick::Brick(float positionX, float positionY)
{
    m_brick.setSize(sf::Vector2f(brick::WIDTH, brick::HEIGHT));
    m_brick.setOutlineThickness(brick::OUTLINE_THICKNESS);
    m_brick.setPosition(positionX, positionY);
    m_brick.setOutlineColor(colors::White);
    m_brick.setFillColor(colors::PaleWhite);
}

void Brick::render(sf::RenderWindow &window) const
{
    window.draw(m_brick);
}

} // namespace breakout
