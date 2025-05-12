#include "Bullet.h"
#include "GameEngine.h"
#include <iostream>

Bullet::Bullet(const sf::Vector2f& startPosition, float speed, sf::Vector2i position, sf::Vector2i spriteSize) {
    std::string fileName = "laser-bolts.png";

    for (int i = 0; i < 2; ++i) {
        sf::IntRect frame({ 6 + position.x * i, position.y }, spriteSize);
        animation.addFrame(frame);
    }

    animation.setFrameTime(0.1f);
    setSize({ 4, 4 });
    setPosition(startPosition);
    setTexture(fileName, animation.getCurrentFrame());
    this->speed = speed;
}

void Bullet::update() {
    float deltaTime = GameEngine::getInstance().getDeltaTime();
    sf::Vector2f pos = getPosition();
    pos.y += speed * deltaTime;
    setPosition(pos);
    animation.update();

    if (sprite) {
        sprite->setTextureRect(animation.getCurrentFrame());
        sprite->setPosition(this->getPosition());
        sprite->setScale(this->getSize());
    }
}

void Bullet::render() {}

bool Bullet::isOffScreen() {
    return getPosition().y + getSize().y < 0;
}

float Bullet::getDamage() {
    return this->damage;
}