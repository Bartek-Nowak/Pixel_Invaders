#include "HealthNumber.h"
#include "GameEngine.h"
#include "SpriteComponent.h"
#include <iostream>

HealthNumber::HealthNumber(int healtNumber) {
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();

    for (int i = 0; i < healtNumber; ++i) {
        SpriteComponent* heart = new SpriteComponent("heart.png", { 0, 2 }, { 30, 27 });
        heart->setPosition({ 60.f + i * 50.f, (float)window.getSize().y - 60.f });
        hearts.push_back(heart);
    }
}

void HealthNumber::draw() {
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    for (int i = 0; i < hearts.size(); i++) {
        hearts[i]->draw();
    }
}

void HealthNumber::removeHeart() {
    if (!hearts.empty()) {
        delete hearts.back(); 
        hearts.pop_back();    
    }
}