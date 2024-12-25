#include "headers/Textbox.h"

namespace snake
{
TextBox::TextBox() : TextBox(5, 9, 200, sf::Vector2f(0, 0)) {}

TextBox::TextBox(uint32_t visibleChars, uint32_t charSize, uint32_t width,
                 const sf::Vector2f &screenPosition)
{
    setup(visibleChars, charSize, width, screenPosition);
}

void TextBox::setup(uint32_t visibleChars, uint32_t charSize, uint32_t width,
                    const sf::Vector2f &screenPosition)
{
}

void TextBox::add(const std::string &message) {}

void TextBox::clear() {}

void TextBox::render(sf::RenderWindow &window) {}

} // namespace snake
