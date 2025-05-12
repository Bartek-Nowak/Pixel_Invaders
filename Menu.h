#pragma once
#include "Level.h"
#include "UiComponent.h"
#include <vector>
#include <iostream>

class Menu : public Level {
public:
    Menu();
    ~Menu();
    void update();
    void draw();
private:
    std::vector< UiComponent* > components;
};
