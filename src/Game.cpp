#include "headers/Game.h"

#include <SFML/Window/Event.hpp>

namespace snake
{
void Game::init()
{
    m_window.create(sf::VideoMode(800, 600), "Snake");
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
    }
}

void Game::render()
{
    m_window.clear();
    m_window.display();
}

void shutdown() {}
} // namespace snake
