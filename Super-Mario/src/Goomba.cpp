#include "headers/Goomba.h"

#include "headers/Textures.h"

namespace mario
{

Goomba::Goomba()
    : m_velocity(0.0f, 0.0f), m_position(START_POSITION_X, START_POSITION_Y),
      m_currentAnimation(GoombaAnimations::ALIVE)
{
    m_animations[int(GoombaAnimations::ALIVE)] =
        Animation(0, 0, 30, 30, 2, textures::EnemiesAnimations);
    m_animations[int(GoombaAnimations::DEAD)] =
        Animation(0, 62, 30, 30, 1, textures::EnemiesAnimations);

    m_goomba.setScale(SCALE_X, SCALE_Y);
    m_goomba.setPosition(m_position);
}

void Goomba::update(float deltaTime)
{
    m_position += m_velocity * deltaTime;
    m_goomba.setPosition(m_position);

    m_animations[int(m_currentAnimation)].update(deltaTime);
    m_animations[int(m_currentAnimation)].applyToSprite(m_goomba);
}

void Goomba::setDirection(const sf::Vector2f &direction)
{
    m_velocity = direction * SPEED;
}

void Goomba::render(sf::RenderWindow &window) const
{
    window.draw(m_goomba);
}

} // namespace mario
