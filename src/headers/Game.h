#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
class Game
{
  public:
    Game() = default;
    Game(const Game &) = delete;
    Game(Game &&) = delete;
    Game &operator=(const Game &) = delete;
    Game &operator=(Game &&) = delete;

    void init();
    void run();
    void shutdown();

  private:
    void processEvents();
    void update();
    void render();

  private:
    sf::RenderWindow m_window;
};
} // namespace snake
