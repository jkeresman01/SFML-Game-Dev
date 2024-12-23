#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include <cstdint>

#include "Goomba.h"
#include "Mario.h"

namespace mario
{

class SuperMarioGame
{
  public:
    SuperMarioGame();

    void run();

  private:
    void processEvents();
    void update();
    void render();

  private:
    sf::RenderWindow m_window;
    sf::View m_view;
    sf::Clock m_clock;
    Mario m_mario;
    Goomba m_goomba;

    static constexpr uint32_t SCREEN_WIDTH = 960;
    static constexpr uint32_t SCREEN_HEIGHT = 480;
};

} // namespace mario
