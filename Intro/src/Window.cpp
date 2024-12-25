#include "Window.h"

namespace sfmlgamedev
{
Window::Window()
{
    setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &title, const sf::Vector2u &size)
{
    setup(title, size);
}

Window::~Window()
{
    destroy();
}

void Window::setup(const std::string &title, const sf::Vector2u &size)
{
    m_windowSize = size;
    m_windowTitle = title;
    m_isFullScreen = false;
    m_isDone = false;

    create();
}

void Window::create()
{
    auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}

void Window::destroy()
{
    m_window.close();
}

void Window::update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_isDone = true;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
        {
            toggleFullScreen();
        }
    }
}

void Window::toggleFullScreen()
{
    m_isFullScreen = !m_isFullScreen;
    destroy();
    create();
}

void Window::beginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
    m_window.display();
}

void Window::draw(sf::Drawable &drawable)
{
    m_window.draw(drawable);
}
} // namespace sfmlgamedev
