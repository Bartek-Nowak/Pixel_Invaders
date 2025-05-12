#pragma once
#include "GameComponent.h"

class UiComponent : public GameComponent {
public:
    //virtual ~UiComponent() = default;
    virtual void draw() = 0;
    virtual void render();
    virtual void update();
};
