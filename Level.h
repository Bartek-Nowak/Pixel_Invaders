#pragma once

#include "Enemy.h"
#include "HUD.h"
#include "Background.h"
#include "Player.h"
#include "Explosion.h"
#include <vector>
#include <string>

class Level {
public:

    Level();
    virtual ~Level();

    virtual void render();
    virtual void update();
    virtual void unmount(); 
    virtual void draw();
    std::string music = "level1";
protected:
    HUD* HUD;
    Background* background;
    Player* player;
    std::vector< Enemy* > enemies;
    std::vector< Explosion* > explosions;
    bool playerDead = false;
    float deathTimer = 0.f;
    const float deathDelay = 2.f;

};
