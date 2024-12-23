#include "headers/Mario.h"
#include "headers/Textures.h"

#include <SFML/Graphics.hpp>

namespace mario
{

Mario::Mario()
    : m_velocity(0.0f, 0.0f), m_direction(0.0f, 0.0f),
      m_position(START_POSITION_X, START_POSITION_Y),
      m_currentAnimation(MarioAnimations::RIGHT_WALK)
{
    m_animations[int(MarioAnimations::RIGHT_WALK)] =
        Animation(230, 52, 29, 29, 3, textures::MarioAnimations);
    m_animations[int(MarioAnimations::LEFT_WALK)] =
        Animation(80, 52, 29, 29, 3, textures::MarioAnimations);

    m_mario.setScale(SCALE_X, SCALE_Y);
    m_mario.setPosition(m_position);
}

void Mario::update(float deltaTime)
{
    setDirection();

    m_position += m_velocity * deltaTime;
    m_mario.setPosition(m_position);

    m_animations[int(m_currentAnimation)].update(deltaTime);
    m_animations[int(m_currentAnimation)].applyToSprite(m_mario);
}

void Mario::setDirection()
{
    m_direction.x *= 0.5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_direction.x -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_direction.x += 1.0f;
    }

    m_velocity = m_direction * SPEED;

    if (m_velocity.x > 0.0f)
    {
        m_currentAnimation = MarioAnimations::RIGHT_WALK;
    }

    if (m_velocity.x < 0.0f)
    {
        m_currentAnimation = MarioAnimations::LEFT_WALK;
    }
}

void Mario::render(sf::RenderWindow &window) const
{
    window.draw(m_mario);
}

} // namespace mario
