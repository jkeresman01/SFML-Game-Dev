#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include <filesystem>
#include <unordered_map>

namespace mario
{

typedef std::unordered_map<std::string, sf::Font> FontUnorderedMapT;
typedef std::unordered_map<std::string, sf::Texture> TextureUnorderedMapT;
typedef std::unordered_map<std::string, sf::SoundBuffer> SoundUnorderedBufferMapT;

class ResourceManager
{
  public:
    ResourceManager() = default;
    ResourceManager(const ResourceManager &) = delete;

    ResourceManager operator=(const ResourceManager &) = delete;

    static ResourceManager &Instance();

    const sf::Texture &getTexture(const std::filesystem::path &filepath);
    const sf::Font &getFont(const std::filesystem::path &filepath);
    const sf::SoundBuffer &getSoundfuffer(const std::filesystem::path &filepath);

  private:
    void loadFont(const std::filesystem::path &filepath);
    void loadTexture(const std::filesystem::path &filepath);
    void loadSoundBuffer(const std::filesystem::path &filepath);

  private:
    FontUnorderedMapT m_fonts;
    TextureUnorderedMapT m_textures;
    SoundUnorderedBufferMapT m_soundBuffers;
};

} // namespace mario
