#include "LevelFactory.h"
#include "Menu.h"
#include "Level1.h"
#include "GameOver.h"
#include <iostream>

Level* LevelFactory::createLevel(int id) {
    switch (id) {
    case 1:
        return new Menu();
    case 2:
        return new Level1();
    case 3:
        return new GameOver();
    default:
        return new Menu();
    }
}
