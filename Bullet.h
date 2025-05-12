#pragma once
#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(const sf::Vector2f& startPosition, float speed, sf::Vector2i position, sf::Vector2i spriteSize);
    void update() override;
    void render() override;
    float getDamage();
    bool isOffScreen();

private:
    float damage = 40;
    float speed;
};
