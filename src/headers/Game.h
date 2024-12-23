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
    ~Game() = default;
    Game(const Game &) = delete;
    Game(Game &&) = delete;
    Game &operator=(const Game &) = delete;
    Game &operator=(Game &&) = delete;

    void run();

  private:
    void processEvents();
    void update();
    void render();

  private:
    World m_world;
    sf::Clock m_clock;
    Snake m_snake;
    float m_elapsedTime;
    sf::RenderWindow m_window;
};
} // namespace snake
