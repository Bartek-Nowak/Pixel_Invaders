#pragma once

#include "Enemy.h"
#include <string>

class EnemiesFactory {
public:
    static Enemy* createEnemy(std::string name);
};
