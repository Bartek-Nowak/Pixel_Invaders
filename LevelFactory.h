#pragma once

#include "Level.h"

class LevelFactory {
public:
    static Level* createLevel(int id);
};
