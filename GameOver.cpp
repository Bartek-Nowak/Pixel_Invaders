#include "GameOver.h"
#include "GameEngine.h"
#include "GameEngineConfig.h"
#include "UiComponent.h"
#include "Background.h"
#include "Button.h"
#include "SpriteComponent.h"
#include "TextContainer.h"
#include "HUD.h"
#include <string>
#include <iostream>

GameOver::GameOver() {
    music = "over";
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    float centerX = window.getSize().x / 2.f;
    float centerY = window.getSize().y / 2.f;

    Background* background = new Background("Green_Nebula_05.png");
    components.push_back(background);

    scoreText = new TextContainer("PressStart2P", "Score: " + std::to_string(HUD::getInstance()->getScore()));
    scoreText->setPosition(centerX - scoreText->getSize().x / 2.f, centerY - scoreText->getSize().y / 2.f);
    components.push_back(scoreText);

    Button* closeButton = new Button("Close");
    closeButton->setPosition({ centerX - closeButton->getSize().x / 2.f , window.getSize().y - 350.f});
    closeButton->setCallback([]() {
        sf::RenderWindow& window = GameEngine::getInstance().getWindow();
        window.close();
        });
    components.push_back(closeButton);

}

GameOver::~GameOver() {
    for (UiComponent* component : components) {
        delete component;
    }
    components.clear();
}


void GameOver::draw() {
    for (UiComponent* component : components) {
        component->draw();
    }
}

void GameOver::update() {
    GameEngine::getInstance().showCursor(true);
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    scoreText->setText("Score: " + std::to_string(HUD::getInstance()->getScore()));
    scoreText->setPosition(window.getSize().x / 2.f - scoreText->getSize().x / 2.f, window.getSize().y / 2.f - scoreText->getSize().y / 2.f);
    for (UiComponent* component : components) {
        component->update();
    }
}
