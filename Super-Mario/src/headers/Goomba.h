#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <cstdint>
#include <filesystem>

#include "Animation.h"

namespace mario
{

enum class GoombaAnimations
{
    ALIVE = 0,
    DEAD = 1,
    COUNT = 2,
};

class Goomba
{
  public:
    Goomba();

    void render(sf::RenderWindow &window) const;

    void update(float deltaTime);

    void setDirection(const sf::Vector2f &direction);

    sf::Vector2f getPosition() const { return m_position; }

  private:
    sf::Sprite m_goomba;
    sf::Vector2f m_velocity;
    sf::Vector2f m_position;
    GoombaAnimations m_currentAnimation;
    Animation m_animations[int(GoombaAnimations::COUNT)];

    static constexpr float SPEED = 100.0f;

    static constexpr float SCALE_X = 2.0f;
    static constexpr float SCALE_Y = 2.0f;

    static constexpr uint32_t START_POSITION_X = 300;
    static constexpr uint32_t START_POSITION_Y = 200;
};

} // namespace mario
