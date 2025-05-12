#include "Background.h"
#include "TextureManager.h"
#include "GameEngine.h"
#include "GameEngineConfig.h"

Background::Background(std::string fileName) {
    setTexture(fileName);
}

void Background::draw() {
    if (this->sprite != nullptr) {
        sf::RenderWindow& window = GameEngine::getInstance().getWindow();
        window.draw(*sprite);
    }
}

void Background::setTexture(std::string fileName) {
    this->texture = TextureManager::getInstance().getTexture(fileName);

    if (this->texture != nullptr) {
        if (sprite) delete sprite;
        sprite = new sf::Sprite(*texture);
        sprite->setPosition({0,0});
        sprite->setScale({ 3, 3 });
    }
}