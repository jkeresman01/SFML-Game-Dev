#pragma once

#include <SFML/Graphics.hpp>

#include <list>

#include "Background.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "ResourceManager.h"

namespace breakout
{

class BreakoutGame
{
  public:
    BreakoutGame();
    void run();

  private:
    void processEvents();
    void update();
    void render();
    void reset();

    void renderBricks(sf::RenderWindow &window) const;
    void resetBricks();

  private:
    sf::RenderWindow m_window;
    Paddle m_paddle;
    Ball m_ball;
    Background m_background;
    ResourceManager m_resourceManager;
    std::list<Brick> m_bricks;
};

} // namespace breakout
