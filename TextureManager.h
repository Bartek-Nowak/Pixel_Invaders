#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    static TextureManager& getInstance();

    sf::Texture* getTexture(const std::string& filename);

private:
    TextureManager();
    ~TextureManager();

    std::map<std::string, sf::Texture*> textures;
};