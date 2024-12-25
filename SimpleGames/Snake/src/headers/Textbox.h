#pragma once

#include <cstdint>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake
{
typedef std::vector<std::string> MessageContainerT;

class TextBox
{
  public:
    TextBox();
    TextBox(uint32_t visibleChars, uint32_t charSize, uint32_t width,
            const sf::Vector2f &screenPosition);

    ~TextBox() { clear(); };

    void setup(uint32_t visibleChars, uint32_t charSize, uint32_t width,
               const sf::Vector2f &screenPosition);

    void add(const std::string &message);
    void clear();
    void render(sf::RenderWindow &window);

  private:
    MessageContainerT m_messages;
    uint32_t m_numVisible;

    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_text;
};
} // namespace snake
