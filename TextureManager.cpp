#include "TextureManager.h"
#include "GameEngineConfig.h"
#include <iostream>

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {
    // Usuñ tekstury z pamiêci
    std::map<std::string, sf::Texture*>::iterator it;
    for (it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
    textures.clear();
}

sf::Texture* TextureManager::getTexture(const std::string& filename) {
    // SprawdŸ, czy tekstura ju¿ jest w mapie
    std::map<std::string, sf::Texture*>::iterator it = textures.find(filename);
    if (it != textures.end()) {
        return it->second;
    }

    // Jeœli nie ma, za³aduj i zapisz
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(GameEngineConfig::SPRITE_PATH + filename)) {
        std::cout << "B³¹d ³adowania tekstury: " << filename << std::endl;
        delete texture;
        return nullptr;
    }

    textures[filename] = texture;
    return texture;
}
