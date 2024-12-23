#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.h"

#include <cstdint>
#include <filesystem>

namespace mario
{

enum class MarioAnimations
{
    RIGHT_WALK = 0,
    LEFT_WALK = 1,
    COUNT = 2,
};

class Mario
{
  public:
    Mario();

    void render(sf::RenderWindow &window) const;

    void processEvents();

    void update(float deltaTime);

    sf::Vector2f getPosition() const { return m_position; }

  private:
    void setDirection();

  private:
    sf::Sprite m_mario;
    sf::Vector2f m_velocity;
    sf::Vector2f m_direction;
    sf::Vector2f m_position;
    MarioAnimations m_currentAnimation;
    Animation m_animations[int(MarioAnimations::COUNT)];

    static constexpr float SPEED = 100.0f;

    static constexpr float SCALE_X = 2.0f;
    static constexpr float SCALE_Y = 2.0f;

    static constexpr uint32_t START_POSITION_X = 400;
    static constexpr uint32_t START_POSITION_Y = 300;
};

} // namespace mario
