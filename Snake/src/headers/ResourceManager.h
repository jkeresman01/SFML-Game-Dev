#pragma once

#include <SFML/Graphics/Font.hpp>

#include <filesystem>
#include <unordered_map>

namespace mario
{

typedef std::unordered_map<std::string, sf::Font> FontUnorderedMapT;

class ResourceManager
{
  public:
    ResourceManager() = default;
    ResourceManager(const ResourceManager &) = delete;

    ResourceManager operator=(const ResourceManager &) = delete;

    static ResourceManager &Instance();

    const sf::Font &getFont(const std::filesystem::path &filepath);

  private:
    void loadFont(const std::filesystem::path &filepath);

  private:
    FontUnorderedMapT m_fonts;
};

} // namespace mario
