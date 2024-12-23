#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <list>

#include "Brick.h"
#include "Paddle.h"

namespace breakout
{

class Ball
{
  public:
    Ball();

    void update(const Paddle &paddle, std::list<Brick> &bricks);
    void render(sf::RenderWindow &window) const;
    void reset();
    void start();

    sf::Vector2f getPosition() const { return m_ball.getPosition(); }
    sf::Vector2f getVelocity() const { return m_velocity; };
    float getRadius() const { return m_ball.getRadius(); }

  private:
    float calculateSpeed();
    float calculateBounceAngleInRadians(const Paddle &paddle);
    float calculateRelativeIntersectX(const Paddle &paddle);

    bool isBallHittingVerticalBorder();
    bool isBallHittingTopBorder();
    bool isBallHittingBottomBorder();
    bool isBallIntersectingPaddle(const Paddle &paddle);

    void changeBallTrajectory(const Paddle &paddle);
    void checkForBrickHits(std::list<Brick> &bricks);

  private:
    sf::CircleShape m_ball;
    sf::Vector2f m_velocity;
    sf::Sound m_brickHitSoundEffect;
};

} // namespace breakout
