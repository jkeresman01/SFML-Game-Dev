#include "headers/Ball.h"

#include <SFML/System/Vector2.hpp>

#include <cmath>
#include <list>

#include "headers/Colors.h"
#include "headers/GameConstants.h"
#include "headers/ResourceManager.h"
#include "headers/Sound.h"

namespace breakout
{

Ball::Ball() : m_velocity(0.0f, 0.0f)
{
    m_ball.setRadius(ball::RADIUS);
    m_ball.setFillColor(colors::White);
    m_brickHitSoundEffect.setBuffer(ResourceManager::Instance().getSoundBugffer(sound::BrikHit));

    reset();
}

void Ball::render(sf::RenderWindow &window) const
{
    window.draw(m_ball);
}

void Ball::start()
{
    bool isBallMoving = m_velocity.x != 0 or m_velocity.y != 0;
    if (!isBallMoving)
    {
        m_velocity = {0, ball::VELOCITY_Y_COMPONENT};
    }
}

void Ball::reset()
{
    m_ball.setPosition(screen::WIDTH / 2 - m_ball.getRadius(),
                       screen::HEIGHT / 2 - m_ball.getRadius());
    m_velocity = {0, 0};
}

void Ball::update(const Paddle &paddle, std::list<Brick> &bricks)
{
    m_ball.move(m_velocity);

    if (isBallHittingVerticalBorder())
    {
        m_velocity.x = -m_velocity.x;
    }

    if (isBallHittingTopBorder())
    {
        m_velocity.y = -m_velocity.y;
    }

    if (isBallHittingBottomBorder())
    {
        reset();
    }

    if (isBallIntersectingPaddle(paddle))
    {
        changeBallTrajectory(paddle);
    }

    checkForBrickHits(bricks);
}

bool Ball::isBallHittingBottomBorder()
{
    return m_ball.getPosition().y > screen::HEIGHT + m_ball.getRadius() * 2;
}

bool Ball::isBallHittingTopBorder()
{
    return m_ball.getPosition().y < 0;
}

bool Ball::isBallHittingVerticalBorder()
{
    bool isBallOnLeftBorder = m_ball.getPosition().x < 0;
    bool isBallOnRightBorder = m_ball.getPosition().x + m_ball.getRadius() * 2 > screen::WIDTH;

    return isBallOnRightBorder or isBallOnLeftBorder;
}

bool Ball::isBallIntersectingPaddle(const Paddle &paddle)
{
    return m_ball.getGlobalBounds().intersects(paddle.getBounds());
}

void Ball::checkForBrickHits(std::list<Brick> &bricks)
{
    std::list<Brick>::iterator it;
    for (it = bricks.begin(); it != bricks.end();)
    {
        bool isBallIntersectingBrick = m_ball.getGlobalBounds().intersects(it->getBounds());
        if (isBallIntersectingBrick)
        {
            m_velocity.y = -m_velocity.y;
            m_brickHitSoundEffect.play();
            it = bricks.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Ball::changeBallTrajectory(const Paddle &paddle)
{
    float bounceAngleInRadians = calculateBounceAngleInRadians(paddle);
    float speed = calculateSpeed();

    m_velocity.x = speed * std::sin(bounceAngleInRadians);
    m_velocity.y = -speed * std::cos(bounceAngleInRadians);
}

float Ball::calculateSpeed()
{
    float velocityXcomponent = std::pow(m_velocity.x, 2);
    float velocityYcomponent = std::pow(m_velocity.y, 2);

    return std::sqrt(velocityXcomponent + velocityYcomponent);
}

float Ball::calculateBounceAngleInRadians(const Paddle &paddle)
{
    float relativeIntersectX = calculateRelativeIntersectX(paddle);
    float normalizedRelativeIntersectionX = relativeIntersectX / (paddle::WIDTH / 2.0f);

    return normalizedRelativeIntersectionX * (75 * (M_PI / 180.0f));
}

float Ball::calculateRelativeIntersectX(const Paddle &paddle)
{
    float ballCenterX = m_ball.getPosition().x + m_ball.getRadius();
    float paddleCenterX = paddle.getPosition().x + paddle::WIDTH / 2.0f;

    return ballCenterX - paddleCenterX;
}

} // namespace breakout
