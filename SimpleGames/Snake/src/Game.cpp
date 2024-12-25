#include "headers/Game.h"

#include <SFML/Window/Event.hpp>

namespace snake
{

Game::Game()
    : m_window(sf::VideoMode(800, 600), "Snake"), m_world(sf::Vector2u(800, 600)),
      m_snake(m_world.getBlockSize())
{
    srand(time(nullptr));
}

void Game::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            m_snake.getDirection() != Direction::DOWN)
        {
            m_snake.setDirection(Direction::UP);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
            m_snake.getDirection() != Direction::UP)
        {
            m_snake.setDirection(Direction::DOWN);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
            m_snake.getDirection() != Direction::RIGHT)
        {
            m_snake.setDirection(Direction::LEFT);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            m_snake.getDirection() != Direction::LEFT)
        {
            m_snake.setDirection(Direction::RIGHT);
        }
    }
}

void Game::update()
{
    float timeStep = 1.0f / m_snake.getSpeed();

    if (m_clock.getElapsedTime().asSeconds() >= timeStep)
    {
        m_snake.tick();
        m_world.update(m_snake);

        if (m_snake.hasLost())
        {
            m_snake.reset();
        }

        m_clock.restart();
    }
}

void Game::render()
{
    m_window.clear();
    m_world.render(m_window);
    m_snake.render(m_window);
    m_window.display();
}

} // namespace snake
