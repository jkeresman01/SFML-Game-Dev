#pragma once

#include "Snake.h"
#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
class Game
{
  public:
    Game();
    Game(const Game &) = delete;
    Game(Game &&) = delete;
    Game &operator=(const Game &) = delete;
    Game &operator=(Game &&) = delete;

    void run();

  private:
    void processEvents();
    void update();
    void render();
    void restartClock();

  private:
    World m_world;
    Snake m_snake;
    sf::Time m_elapsedTime;
    sf::Clock m_clock;
    sf::RenderWindow m_window;
};
} // namespace snake
