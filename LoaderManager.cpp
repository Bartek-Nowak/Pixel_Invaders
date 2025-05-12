#include "LoaderManager.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "FontManager.h"
#include "GameEngine.h"
#include "GameEngineConfig.h"
#include "TextContainer.h"
#include <iostream>

LoaderManager* LoaderManager::instance = nullptr;

LoaderManager::LoaderManager() {}
LoaderManager::~LoaderManager() {}

LoaderManager* LoaderManager::getInstance() {
    if (!instance) {
        instance = new LoaderManager();
    }
    return instance;
}

void LoaderManager::loadAllAssets() {
    TextureManager::getInstance().getTexture("ship.png");
    TextureManager::getInstance().getTexture("enemy-big.png");
    TextureManager::getInstance().getTexture("enemy-medium.png");
    TextureManager::getInstance().getTexture("enemy-small.png");
    TextureManager::getInstance().getTexture("laser-bolts.png");
    TextureManager::getInstance().getTexture("Blue_Nebula_01.png");
    TextureManager::getInstance().getTexture("Purple_Nebula_01.png");
    TextureManager::getInstance().getTexture("Green_Nebula_05.png");
    TextureManager::getInstance().getTexture("black_hole.png");

    FontManager::getInstance()->loadFont("PressStart2P", GameEngineConfig::FONTS_PATH + "PressStart2P.ttf");

    AudioManager::getInstance()->loadSoundEffect("damage", "damage.ogg");
    AudioManager::getInstance()->loadSoundEffect("shot", "shot.ogg");

    AudioManager::getInstance()->loadMusic("level1", "06_Battle_in_Space_Loop.ogg");
    AudioManager::getInstance()->loadMusic("intro", "03_Racing_Through_Asteroids_Loop.ogg");
    AudioManager::getInstance()->loadMusic("over", "05_Building_a_Colony_Loop.ogg");
}

void LoaderManager::showLoadingScreen() {
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();

    TextContainer loadingText("PressStart2P", "Loading...");
    loadingText.setCharacterSize(20);
    loadingText.setPosition(window.getSize().x - loadingText.getSize().x - 50, window.getSize().y - loadingText.getSize().y - 50);
    loadingText.setColor(sf::Color::White);

    window.clear(sf::Color::Black);
    loadingText.draw();
    window.display();
}

void LoaderManager::destroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}
