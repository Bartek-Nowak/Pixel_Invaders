#pragma once
#include "Level.h"
#include <iostream>

class Level1 : public Level {
public:
    Level1();
    ~Level1();
    void update();
    int direction = 1;
};
