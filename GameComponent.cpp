#include "GameComponent.h"
#include "GameEngine.h"
#include <iostream>

GameComponent::GameComponent() {
}

GameComponent::~GameComponent() {
}

void GameComponent::setSize(sf::Vector2f size) {
	this->size = size;
};

void  GameComponent::setPosition(sf::Vector2f position) {
	this->position = position;
};

sf::Vector2f GameComponent::getSize() {
	int scale = GameEngine::getInstance().getScale();
	
	sf::Vector2f vector = sf::Vector2f(this->size.x * scale, this->size.y * scale);

	return vector;
};

sf::Vector2f GameComponent::getPosition() {
	float scale = GameEngine::getInstance().getScale();
	//std::cout << scale << std::endl;
	sf::Vector2f vector = sf::Vector2f(this->position.x * scale, this->position.y * scale);

	return vector;
};