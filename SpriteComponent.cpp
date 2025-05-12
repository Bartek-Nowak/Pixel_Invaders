#include "SpriteComponent.h"
#include "GameEngine.h"
#include "TextureManager.h"
#include <iostream>

SpriteComponent::SpriteComponent(std::string textureName, sf::Vector2i frameBegin, sf::Vector2i frameSize, bool animation, int widthFrame, int heightFrame) {
    if (animation) {
        for (int i = 0; i < heightFrame; i++) {
            for (int j = 0; j < widthFrame; j++) {
                sf::IntRect frame({ frameBegin.x + frameSize.x * j, frameBegin.y + frameSize.y * i }, frameSize);
                this->animation.addFrame(frame);
            }
        }
    }
    else {
        sf::IntRect frame(frameBegin, frameSize);
        this->animation.addFrame(frame);
    }

    sf::RenderWindow& window = GameEngine::getInstance().getWindow();

    this->animation.setFrameTime(0.1f);

    setSize({ 2, 2 });

    setTexture(textureName, this->animation.getCurrentFrame());
}

SpriteComponent::~SpriteComponent() {
    if (sprite) {
        delete sprite;
        sprite = nullptr;
    }
}

void SpriteComponent::draw() {
    if (this->sprite != nullptr) {
        sf::RenderWindow& window = GameEngine::getInstance().getWindow();
        this->sprite->setScale(this->getSize());
        this->sprite->setPosition(this->getPosition());
        window.draw(*sprite);
    }
}

void SpriteComponent::setTexture(std::string fileName, sf::IntRect frame) {
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


void SpriteComponent::render() {}

void SpriteComponent::update() {
    animation.update();
    if (sprite) {
        sprite->setTextureRect(animation.getCurrentFrame());
        sprite->setPosition(this->getPosition());
        sprite->setScale(this->getSize());
    }
}

sf::Vector2f SpriteComponent::getSpriteSize() {
    return this->sprite->getGlobalBounds().size;
}