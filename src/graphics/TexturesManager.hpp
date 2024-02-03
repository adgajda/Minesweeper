#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <string_view>
#include <unordered_map>

namespace minesweeper
{
namespace graphics
{

enum class MinesweeperTextures
{
    Empty,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Mine,
    MineHit,
    Flag,
    Covered,
};

template<typename T>
class TexturesManager final
{
public:
    TexturesManager(std::string_view texturesPath) : texturesPath_{ texturesPath }
    {
    }

    void loadTexture(std::string fileName, T textureType)
    {
        const auto loadTextureFromFile = [](std::string path) {
            sf::Texture texture;
            texture.loadFromFile(path);
            return texture;
        };
        textures_.emplace(textureType, loadTextureFromFile(texturesPath_ + fileName));
    }

    [[nodiscard]] const sf::Texture& getTexture(T textureType)
    {
        if (const auto it = textures_.find(textureType); it != textures_.end())
        {
            return it->second;
        }

        throw std::runtime_error("Texture not loaded");
    }

private:
    std::string texturesPath_;
    std::unordered_map<T, sf::Texture> textures_;
};

}// namespace graphics
}// namespace minesweeper
