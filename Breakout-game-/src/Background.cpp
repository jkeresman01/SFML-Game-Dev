#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/ResourceManager.h"
#include "headers/Texture.h"

namespace breakout
{

Background::Background()
{
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
    m_background.setTexture(ResourceManager::Instance().getTexture(texture::Background));
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace breakout
