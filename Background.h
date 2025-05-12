#pragma once
#include <SFML/Graphics.hpp>
#include "UiComponent.h"

class Background: public UiComponent {
public:
    Background(std::string filename);
    void draw() override;

private:
    sf::Sprite* sprite = nullptr;
    sf::Texture* texture = nullptr;

    void setTexture(std::string fileName);
};
