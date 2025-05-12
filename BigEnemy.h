#pragma once

#include "Enemy.h"

class BigEnemy : public Enemy {
public:
    BigEnemy();
    ~BigEnemy();
    void update() override;
    void render() override;
};

