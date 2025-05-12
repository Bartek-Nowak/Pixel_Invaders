#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <vector>

class Enemy : public Entity{
public:
    Enemy();
    ~Enemy();
    virtual void render() = 0;
    virtual void update() = 0;
    void takeDamage(float damage);
    float getHealth();
    bool isDead();
    int getScore();
    void draw();
    std::vector<Bullet*>& getBullets();

protected:
    float health = 100;
    int score = 20;
    std::vector<Bullet*> bullets;
    float shootCooldown = 0.25f;
    float shootTimer = 0.f;
    void shot();
};
