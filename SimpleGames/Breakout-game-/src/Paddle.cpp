#include "headers/Paddle.h"

#include <SFML/System/Vector2.hpp>

#include "headers/Colors.h"
#include "headers/GameConstants.h"

namespace breakout
{

Paddle::Paddle() : m_speed(paddle::SPEED)
{
    m_paddle.setSize(sf::Vector2f(paddle::WIDTH, paddle::HEIGHT));
    m_paddle.setOutlineThickness(paddle::OUTLINE_THICKNESS);
    m_paddle.setPosition(paddle::POSITION_X, paddle::POSITION_Y);
    m_paddle.setFillColor(colors::PaleWhite);
    m_paddle.setOutlineColor(colors::White);
}

void Paddle::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveRight();
    }
}

void Paddle::render(sf::RenderWindow &window) const
{
    window.draw(m_paddle);
}

void Paddle::moveLeft()
{
    bool isPaddlePositionOnLeftBorder = m_paddle.getPosition().x <= 0;

    if (isPaddlePositionOnLeftBorder)
    {
        m_paddle.setPosition(0, m_paddle.getPosition().y);
    }
    else
    {
        m_paddle.move(-m_speed, 0);
    }
}

void Paddle::moveRight()
{
    bool isPaddlePositionOnRightBorder =
        m_paddle.getPosition().x + m_paddle.getSize().x >= screen::WIDTH;

    if (isPaddlePositionOnRightBorder)
    {
        m_paddle.setPosition(screen::WIDTH - paddle::WIDTH, m_paddle.getPosition().y);
    }
    else
    {
        m_paddle.move(m_speed, 0);
    }
}

void Paddle::setPosition(float positionX, float positionY)
{
    m_paddle.setPosition(positionX, positionY);
}
} // namespace breakout
