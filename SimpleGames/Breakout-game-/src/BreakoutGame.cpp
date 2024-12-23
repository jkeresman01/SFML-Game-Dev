#include "headers/BreakoutGame.h"

#include "headers/GameConstants.h"
#include <SFML/System/Vector2.hpp>

namespace breakout
{

BreakoutGame::BreakoutGame()
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "", sf::Style::None), m_paddle(),
      m_ball(), m_background(), m_resourceManager()

{
    m_window.setPosition(sf::Vector2i(screen::POSITION_X, screen::POSITION_Y));

    reset();
}

void BreakoutGame::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void BreakoutGame::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        m_ball.start();
    }
}

void BreakoutGame::update()
{
    m_paddle.update();
    m_ball.update(m_paddle, m_bricks);
}

void BreakoutGame::render()
{
    m_window.clear();
    m_background.render(m_window);
    m_paddle.render(m_window);
    m_ball.render(m_window);
    renderBricks(m_window);
    m_window.display();
}

void BreakoutGame::renderBricks(sf::RenderWindow &window) const
{
    std::for_each(m_bricks.begin(), m_bricks.end(),
                  [&window](const Brick &b) { b.render(window); });
}

void BreakoutGame::reset()
{
    resetBricks();
    m_ball.reset();
}

void BreakoutGame::resetBricks()
{
    m_bricks.clear();

    for (size_t i = 0; i < brickwall::ROWS; ++i)
    {
        for (size_t j = 0; j < brickwall::COLUMNS; ++j)
        {
            float positionX = brick::START_POSTION_X + j * (brick::WIDTH + brick::SPACING_X);
            float positionY = brick::START_POSTION_Y + i * (brick::HEIGHT + brick::SPACING_Y);

            m_bricks.emplace_back(positionX, positionY);
        }
    }
}

} // namespace breakout
