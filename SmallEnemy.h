#pragma once

#include "Enemy.h"

class SmallEnemy : public Enemy {
public:
    SmallEnemy();
    ~SmallEnemy();
    void update() override;
    void render() override;
};

