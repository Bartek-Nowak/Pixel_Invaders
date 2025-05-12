#include "Menu.h"
#include "GameEngine.h"
#include "GameEngineConfig.h"
#include "UiComponent.h"
#include "Background.h"
#include "Button.h"
#include "SpriteComponent.h"
#include <string>
#include <iostream>

Menu::Menu() {
    music = "intro";
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    float centerX = window.getSize().x / 2.f;
    float centerY = window.getSize().y / 2.f;

    Background* background = new Background("Purple_Nebula_01.png");
    components.push_back(background);

    SpriteComponent* black_hole = new SpriteComponent("black_hole.png", { 20, 27 }, { 200, 200 }, true, 50);
    black_hole->setPosition({ centerX / 2.f + 20.f, centerY / 2.f + 20.f });
    components.push_back(black_hole);

    SpriteComponent* logo = new SpriteComponent("logo.png", { 0, 0 }, { 500, 134 });
    logo->setPosition({ centerX, centerY - logo->getSpriteSize().y / 2.f});
    components.push_back(logo);

    Button* startButton = new Button("Start");
    startButton->setPosition({ centerX - startButton->getSize().x / 2.f, logo->getPosition().y + startButton->getSize().x });
    startButton->setCallback([]() {
        LevelManager::getSingleton()->nextLevel();
        });
    components.push_back(startButton);

    Button* closeButton = new Button("Close");
    closeButton->setPosition({ startButton->getPosition().x ,startButton->getPosition().y + startButton->getSize().y + 90.f });
    closeButton->setCallback([]() {
        sf::RenderWindow& window = GameEngine::getInstance().getWindow();
        window.close();
     });
    components.push_back(closeButton);

    TextContainer* author = new TextContainer("PressStart2P", "Bartlomiej Nowak");
    author->setCharacterSize(20);
    author->setPosition(window.getSize().x - author->getSize().x - 50, window.getSize().y - author->getSize().y - 50);
    components.push_back(author);
}

Menu::~Menu() {
    for (UiComponent* component : components) {
        delete component;
    }
    components.clear();
}


void Menu::draw() {
    for (UiComponent* component : components) {
        component->draw();
    }
}

void Menu::update() {
    GameEngine::getInstance().showCursor(true);
    for (UiComponent* component : components) {
        component->update();
    }
}
