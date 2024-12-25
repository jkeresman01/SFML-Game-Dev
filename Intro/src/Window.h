#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace sfmlgamedev
{
class Window
{
  public:
    Window();
    Window(const std::string &title, const sf::Vector2u &size);
    ~Window();

    void beginDraw();
    void endDraw();

    void update();

    bool isDone() const { return m_isDone; };
    bool isFullScreen() const { return m_isFullScreen; };
    sf::Vector2u getWindowSize() const { return m_windowSize; };

    void toggleFullScreen();
    void draw(sf::Drawable &drawable);

  private:
    void setup(const std::string &title, const sf::Vector2u &size);
    void destroy();
    void create();

  private:
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    bool m_isDone;
    bool m_isFullScreen;
};
} // namespace sfmlgamedev
