#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#pragma once
#include <SFML/Graphics.hpp>
#include "LevelManager.h"
#include "AudioManager.h"

class GameEngine {
private:
    sf::RenderWindow window;
    float windowScale = -1.f;
    sf::Clock deltaClock;
    float deltaTime = 0.f;;
    
    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

    
    void init();
    void render();
    void update();
    void setScale();

public:
    static GameEngine& getInstance();
    GameEngine();
    LevelManager* levelManager;
    AudioManager* audioManager;

    void start();
    sf::RenderWindow& getWindow();
    float getScale() const;
    float getDeltaTime() const;
    void showCursor(bool value);
    std::vector<Explosion*> explosions;
    void addExplosion(Explosion* explosion);
};

#endif