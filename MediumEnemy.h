#pragma once

#include "Enemy.h"

class MediumEnemy : public Enemy {
public:
    MediumEnemy();
    ~MediumEnemy();
    void update() override;
    void render() override;
};

