#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity {
public:
    static Player* getInstance();

    void update() override;
    void render() override;
    void shot();
    void move();
    void draw();

    std::vector<Bullet*>& getBullets();
    void takeDamage();
    int getHealth();
    bool isDead();

private:
    Player(); 
    ~Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    static Player* instance;

    std::vector<Bullet*> bullets;

    float velocityX = 0.f;
    float velocityY = 0.f;
    const float maxSpeed = 800.f;
    const float acceleration = 2000.f;
    const float deceleration = 2500.f;
    float shootCooldown = 0.25f;
    float shootTimer = 0.f;
    int health = 3;
    float invincibilityTime = 0.f;
    const float maxInvincibilityTime = 2.f;
    bool visible = true;
    float blinkTimer = 0.f;
    const float blinkInterval = 0.1f;
    bool recentlyHit = false;
};
