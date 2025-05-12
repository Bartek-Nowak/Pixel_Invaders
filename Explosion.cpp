#include "Explosion.h"
#include "GameEngine.h"

Explosion::Explosion(const sf::Vector2f& position) {
    sprite = new SpriteComponent("explosion.png", { 0, 0 }, { 16, 16 }, true, 5);
    sprite->setPosition(position);
    sprite->setSize({ 4.f, 4.f });
}

void Explosion::update() {
    float deltaTime = GameEngine::getInstance().getDeltaTime();
    timer += deltaTime;
    sprite->update();
}

void Explosion::draw() {
    sprite->draw();
}

bool Explosion::isFinished() const {
    return timer >= duration;
}
