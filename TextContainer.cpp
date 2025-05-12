#include "TextContainer.h"
#include "GameEngine.h"
#include "GameEngineConfig.h"
#include <iostream>

TextContainer::TextContainer(const std::string& fontName, const std::string& initialText) {
    if (!FontManager::getInstance()->loadFont(fontName, GameEngineConfig::FONTS_PATH + fontName + ".ttf")) {
        std::cout << "Nie uda³o siê za³adowaæ czcionki!" << std::endl;
    }

    font = FontManager::getInstance()->getFont(fontName);

    if (font) {
        text = new sf::Text(*font);
        text->setString(initialText);
        text->setFillColor(sf::Color::White);
        text->setCharacterSize(48);
    }
    else {
        text = nullptr;
    }
}

TextContainer::~TextContainer() {
    if (text) delete text;
}

void TextContainer::setText(const std::string& str) {
    if (text) text->setString(str);
}

void TextContainer::setPosition(float x, float y) {
    if (text) text->setPosition({ x, y });
}

void TextContainer::setColor(const sf::Color& color) {
    if (text) text->setFillColor(color);
}

void TextContainer::setCharacterSize(unsigned int size) {
    if (text) text->setCharacterSize(size);
}

void TextContainer::draw() {
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    if (text) {
        window.draw(*text);
    };
}

sf::Vector2f TextContainer::getSize() {
    if (text) {
        sf::FloatRect bounds = text->getGlobalBounds();
        return bounds.size;
    }
    return sf::Vector2f(0.f, 0.f);
}