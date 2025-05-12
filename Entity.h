#pragma once
#include "GameComponent.h"
#include "Animation.h"
#include <string>

class Entity : public GameComponent {
public:

    Entity();
    ~Entity();
    virtual void render() = 0;
    virtual void update() = 0;
    void draw();
    void setTexture(std::string fileName, sf::IntRect frame);
    sf::FloatRect getBounds();

protected:
    sf::Sprite* sprite = nullptr;
    sf::Texture* texture = nullptr;
    Animation animation;
};
