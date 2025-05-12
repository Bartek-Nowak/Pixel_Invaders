#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class FontManager {
public:
    static FontManager* getInstance();

    bool loadFont(const std::string& name, const std::string& filename);
    sf::Font* getFont(const std::string& name);

private:
    FontManager(); // prywatny konstruktor
    ~FontManager();
    static FontManager* instance;

    std::map<std::string, sf::Font*> fonts;
};
