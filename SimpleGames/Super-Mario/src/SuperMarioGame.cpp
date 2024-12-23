#include "headers/SuperMarioGame.h"

#include <SFML/Graphics.hpp>

namespace mario
{

SuperMarioGame::SuperMarioGame()
    : m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Super Mario"),
      m_view(sf::Vector2f(0, 0), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT))
{
}

void SuperMarioGame::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void SuperMarioGame::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void SuperMarioGame::update()
{
    auto deltaTime = m_clock.getElapsedTime().asSeconds();

    m_mario.update(deltaTime);
    m_goomba.update(deltaTime);

    m_view.setCenter(m_mario.getPosition().x, m_mario.getPosition().y);
    m_window.setView(m_view);

    m_clock.restart();
}

void SuperMarioGame::render()
{
    m_window.clear();
    m_mario.render(m_window);
    m_goomba.render(m_window);
    m_window.display();
}

} // namespace mario
