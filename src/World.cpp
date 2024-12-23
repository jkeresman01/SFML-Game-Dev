#include "headers/World.h"

#include <iostream>

namespace snake
{
World::World(const sf::Vector2u &windowSize) : m_blockSize(16), m_windowSize(windowSize)
{
    respwanApple();

    for (size_t i = 0; i < 4; ++i)
    {
        m_bounds[i].setFillColor(sf::Color(150, 0, 0));

        if (!(i + 1) % 2)
        {
            m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
        }
        else
        {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.x));
        }

        if (i < 2)
        {
            m_bounds[i].setPosition(0, 0);
        }
        else
        {
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
        }
    }
}

void World::respwanApple()
{
    std::cout << "Respawing apple!" << std::endl;

    uint32_t maxPositionX = (m_windowSize.x / m_blockSize) - 2;
    uint32_t maxPositionY = (m_windowSize.y / m_blockSize) - 2;

    uint32_t applePositionX = rand() % maxPositionX + 1;
    uint32_t applePositionY = rand() % maxPositionY + 1;

    m_appleCoordinates = sf::Vector2i(applePositionX, applePositionY);

    m_apple.setPosition(m_appleCoordinates);
}

void World::update(Snake &snake)
{
    bool didSnakeEatApple = snake.getPosition() == m_appleCoordinates;

    if (didSnakeEatApple)
    {
        snake.extend();
        snake.increaseScore();
        respwanApple();
    }

    if (isPlayerOutsideTheWorld(snake))
    {
        snake.lose();
    }
}

bool World::isPlayerOutsideTheWorld(const Snake &snake)
{
    uint32_t gridSizeX = m_windowSize.x / m_blockSize;
    uint32_t gridSizeY = m_windowSize.y / m_blockSize;

    bool isOutsideLeft = snake.getPosition().x <= 0;
    bool isOutsideRight = snake.getPosition().x >= gridSizeX - 1;

    bool isOutsideDown = snake.getPosition().y <= 0;
    bool isOutsideTop = snake.getPosition().y >= gridSizeY - 1;

    return isOutsideTop or isOutsideDown or isOutsideRight or isOutsideLeft;
}

void World::render(sf::RenderWindow &window)
{
    for (size_t i = 0; i < 4; ++i)
    {
        window.draw(m_bounds[i]);
    }

    m_apple.render(window);
}
} // namespace snake
