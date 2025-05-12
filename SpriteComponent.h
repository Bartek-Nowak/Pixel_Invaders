#pragma once
#include <SFML/Graphics.hpp>
#include "UiComponent.h"
#include "Animation.h"
#include <iostream>

class SpriteComponent : public UiComponent {
public:
	SpriteComponent(std::string textureName, sf::Vector2i frameBegin, sf::Vector2i frameSize, bool animation = false, int widthFrame = 1, int heightFrame = 1);
	~SpriteComponent();
	void update() override;
	void render() override;
	void draw();
	sf::Vector2f getSpriteSize();
private:
	Animation animation;
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	void setTexture(std::string fileName, sf::IntRect frame);
};