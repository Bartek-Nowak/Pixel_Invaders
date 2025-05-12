// Explosion.h
#pragma once
#include "SpriteComponent.h"

class Explosion {
public:
    Explosion(const sf::Vector2f& position);
    void update();
    void draw();
    bool isFinished() const;

private:
    SpriteComponent* sprite;
    float timer = 0.f;
    float duration = 0.5f; // czas trwania animacji w sekundach
};
