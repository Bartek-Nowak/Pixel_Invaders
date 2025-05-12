#pragma once
#include <SFML/Graphics.hpp>
#include "FontManager.h"
#include "UiComponent.h"
#include <string>

class TextContainer : public UiComponent {
public:
    TextContainer(const std::string& fontName, const std::string& initialText = "");

    ~TextContainer();

    void setText(const std::string& str);

    void setPosition(float x, float y);

    void setColor(const sf::Color& color);

    void setCharacterSize(unsigned int size);

    void draw() override;

    sf::Vector2f getSize();

private:
    sf::Font* font = nullptr;
    sf::Text* text = nullptr;
};
