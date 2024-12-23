#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <filesystem>

namespace breakout
{

class Background
{
  public:
    Background();

    void render(sf::RenderWindow &window) const;

  private:
    sf::Sprite m_background;
};

} // namespace breakout
