#include "FontManager.h"
#include <iostream>

FontManager* FontManager::instance = 0;

FontManager::FontManager() {}

FontManager::~FontManager() {
    for (std::map<std::string, sf::Font*>::iterator it = fonts.begin(); it != fonts.end(); ++it) {
        delete it->second;
    }
}

FontManager* FontManager::getInstance() {
    if (instance == 0) {
        instance = new FontManager();
    }
    return instance;
}

bool FontManager::loadFont(const std::string& name, const std::string& filename) {
    if (fonts.find(name) != fonts.end()) {
        return true;
    }

    sf::Font* font = new sf::Font();
    if (!font->openFromFile(filename)) {
        delete font;
        std::cout << "Nie uda³o siê za³adowaæ czcionki: " << filename << std::endl;
        return false;
    }

    fonts[name] = font;
    return true;
}

sf::Font* FontManager::getFont(const std::string& name) {
    if (fonts.find(name) != fonts.end()) {
        return fonts[name];
    }
    return NULL;
}
