#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Directions.h"
#include "SnakeSegment.h"

#include <cstdint>
#include <vector>

namespace snake
{
typedef std::vector<SnakeSegment> SnakeContainerT;

class Snake
{
  public:
    Snake(uint32_t blockSize);
    ~Snake() = default;

    void setDirection(const Direction &direction) { m_direction = direction; };

    Direction getDirection() const { return m_direction; };
    uint32_t getSpeed() const { return m_speed; };
    uint32_t getLives() const { return m_lives; };
    uint32_t getScore() const { return m_score; };
    bool hasLost() const { return m_lost; };
    sf::Vector2i getPosition() const;
    void increaseScore();

    void lose() { m_lost = true; };
    void toggleLost() { m_lost = !m_lost; };

    void extend();
    void reset();

    void move();
    void tick();
    void cut(uint32_t segment);

    void render(sf::RenderWindow &window);

  private:
    void checkCollision();

  private:
    SnakeContainerT m_snakeBody;
    uint32_t m_blockSize;
    Direction m_direction;
    uint32_t m_speed;
    uint32_t m_lives;
    uint32_t m_score;
    bool m_lost;
    sf::RectangleShape m_body;
};
} // namespace snake
