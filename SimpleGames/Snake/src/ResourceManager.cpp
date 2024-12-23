#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace mario
{

const sf::Font &ResourceManager::getFont(const std::filesystem::path &filepath)
{
    FontUnorderedMapT::iterator it = m_fonts.find(filepath.string());

    if (it == m_fonts.end())
    {
        loadFont(filepath);
        it = m_fonts.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadFont(const std::filesystem::path &filepath)
{
    sf::Font font;

    bool isFontLoadedSuccesfully = font.loadFromFile(filepath);

    if (!isFontLoadedSuccesfully)
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
        return;
    }

    m_fonts.emplace(filepath.string(), font);
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instance;
    return instance;
}

} // namespace mario
