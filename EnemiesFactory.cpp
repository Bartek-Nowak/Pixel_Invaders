#include "EnemiesFactory.h"
#include "Enemy.h"
#include "Enemies.h"
#include "BigEnemy.h"
#include "MediumEnemy.h"
#include "SmallEnemy.h"
#include <string>

Enemy* EnemiesFactory::createEnemy(std::string name) {
    if (name == Enemies::BIG) {
        return new BigEnemy();
    }
    if (name == Enemies::MEDIUM) {
        return new MediumEnemy();
    }
    if (name == Enemies::SMALL) {
        return new SmallEnemy();
    }
}
