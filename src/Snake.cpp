#include "headers/Snake.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
Snake::Snake(uint32_t blockSize)
    : m_blockSize(blockSize), m_body(sf::Vector2f(blockSize - 1, blockSize - 1))
{
    reset();
}

sf::Vector2i Snake::getPosition() const
{
    return m_snakeBody.empty() ? m_snakeBody.front().position : sf::Vector2i(1, 1);
}

void Snake::increaseScore()
{
    m_score += 10;
}

void Snake::reset()
{
    m_snakeBody.clear();

    m_snakeBody.emplace_back(5, 7);
    m_snakeBody.emplace_back(5, 6);
    m_snakeBody.emplace_back(5, 5);

    setDirection(Direction::NONE);

    m_speed = 15;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::tick()
{
    if (m_snakeBody.empty() or m_direction == Direction::NONE)
    {
        return;
    }

    move();
    checkCollision();
}

void Snake::move()
{
    for (size_t i = m_snakeBody.size() - 1; i > 0; --i)
    {
        m_snakeBody[i].position = m_snakeBody[i - 1].position;
    }

    switch (m_direction)
    {
    case Direction::LEFT:
        --m_snakeBody[0].position.x;
        break;
    case Direction::RIGHT:
        ++m_snakeBody[0].position.x;
        break;
    case Direction::UP:
        --m_snakeBody[0].position.y;
        break;
    case Direction::DOWN:
        ++m_snakeBody[0].position.y;
        break;
    default:
        break;
    }
}

void Snake::checkCollision()
{
    if (m_snakeBody.size() < 5)
    {
        return;
    }

    SnakeSegment &head = m_snakeBody.front();

    for (auto it = m_snakeBody.begin() + 1; it != m_snakeBody.end(); ++it)
    {
        if (it->position == head.position)
        {
            int segments = m_snakeBody.end() - it;
            cut(segments);
            break;
        }
    }
}

void Snake::cut(uint32_t segment)
{
    for (size_t i = 0; i < segment; ++i)
    {
        m_snakeBody.pop_back();
    }

    --m_lives;

    if (!m_lives)
    {
        lose();
        return;
    }
}

void Snake::render(sf::RenderWindow &window)
{
    if (m_snakeBody.empty())
    {
        return;
    }

    auto head = m_snakeBody.begin();

    m_body.setFillColor(sf::Color::Yellow);

    uint32_t positionX = head->position.x * m_blockSize;
    uint32_t positionY = head->position.y * m_blockSize;

    m_body.setPosition(positionX, positionY);

    window.draw(m_body);

    m_body.setFillColor(sf::Color::Green);

    for (auto it = m_snakeBody.begin() + 1; it != m_snakeBody.end(); ++it)
    {
        positionX = it->position.x * m_blockSize;
        positionY = it->position.y * m_blockSize;

        m_body.setPosition(positionX, positionY);
        window.draw(m_body);
    }
}

void Snake::extend()
{
    if (m_snakeBody.empty())
    {
        return;
    }

    SnakeSegment tailHead = m_snakeBody[m_snakeBody.size() - 1];

    if (m_snakeBody.size() > 1)
    {
        SnakeSegment tailBone = m_snakeBody[m_snakeBody.size() - 2];

        if (tailHead.position.x == tailBone.position.x)
        {
            if (tailHead.position.x > tailBone.position.y)
            {
                m_snakeBody.emplace_back(tailHead.position.x, tailHead.position.y + 1);
            }
            else
            {
                m_snakeBody.emplace_back(tailHead.position.x, tailHead.position.y - 1);
            }
        }
        else if (tailHead.position.y == tailBone.position.y)
        {
            if (tailHead.position.y > tailBone.position.x)
            {
                m_snakeBody.emplace_back(tailHead.position.x + 1, tailHead.position.y - 1);
            }
            else
            {
                m_snakeBody.emplace_back(tailHead.position.x - 1, tailHead.position.y - 1);
            }
        }
        else
        {
            if (m_direction == Direction::UP)
            {
                m_snakeBody.emplace_back(tailHead.position.x, tailHead.position.y + 1);
            }
            else if (m_direction == Direction::DOWN)
            {
                m_snakeBody.emplace_back(tailHead.position.x, tailHead.position.y - 1);
            }
            else if (m_direction == Direction::LEFT)
            {
                m_snakeBody.emplace_back(tailHead.position.x + 1, tailHead.position.y);
            }
            else if (m_direction == Direction::RIGHT)
            {
                m_snakeBody.emplace_back(tailHead.position.x - 1, tailHead.position.y);
            }
        }
    }
}

} // namespace snake
