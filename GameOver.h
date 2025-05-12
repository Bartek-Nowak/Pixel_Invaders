#pragma once
#include "Level.h"
#include "UiComponent.h"
#include "TextContainer.h"
#include <vector>
#include <iostream>

class GameOver : public Level {
public:
    GameOver();
    ~GameOver();
    void update();
    void draw();
private:
    std::vector< UiComponent* > components;
    TextContainer* scoreText;
};