#include "Entity.h"
#include "TextureManager.h"
#include "GameEngine.h"
#include <iostream>
#include <string>

Entity::Entity() {
}

Entity::~Entity() {
    if (sprite) delete sprite;
}

void Entity::draw() {
    if (this->sprite != nullptr) {
    	sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    	this->sprite->setScale(this->getSize());
    	this->sprite->setPosition(this->getPosition());
    	window.draw(*sprite);
    }
}

void Entity::setTexture(std::string fileName, sf::IntRect frame) {
    this->texture = TextureManager::getInstance().getTexture(fileName);

    if (this->texture != nullptr) {
        if (sprite) delete sprite;
        sprite = new sf::Sprite(*texture);
        sprite->setTextureRect(frame);
        sprite->setOrigin({ (float)frame.size.x / 2.f, (float)frame.size.y / 2.f });
        sprite->setScale(this->getSize());
        sprite->setPosition({ this->getPosition().x, this->getPosition().y });
    }
    else {
        std::cout << "Nie uda³o siê za³adowaæ tekstury: " << fileName << std::endl;
    }
}

sf::FloatRect Entity::getBounds() {
    return sprite->getGlobalBounds();
}