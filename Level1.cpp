#include "Level1.h"
#include "GameEngine.h"
#include "Enemies.h"
#include "EnemiesFactory.h"
#include "AudioManager.h"
#include "HUD.h"
#include "Background.h"
#include "Player.h"
#include <string>

Level1::Level1() {
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();

    this->HUD = HUD::getInstance();
    this->background = new Background("Blue_Nebula_01.png");
    this->player = Player::getInstance();

    float startX = window.getSize().x / 9.0f;
    float startY = window.getSize().y / 8.0f;
    float spacingX = (window.getSize().x - 2 * window.getSize().x / 9.0f) / 9.0f;
    float spacingY = (window.getSize().x - 2 * window.getSize().x / 9.0f) / 9.0f;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 10; ++col) {
            std::string enemiesList[] = { Enemies::BIG, Enemies::MEDIUM, Enemies::SMALL };
            Enemy* enemy = EnemiesFactory::createEnemy(enemiesList[row]);

            enemy->setPosition(sf::Vector2f(startX + col * spacingX, startY + row * spacingY));
            enemies.push_back(enemy);
        }
    }

}

Level1::~Level1() {
}

void Level1::update() {
    Level::update();
    GameEngine::getInstance().showCursor(false);
    float deltaTime = GameEngine::getInstance().getDeltaTime();
    sf::RenderWindow& window = GameEngine::getInstance().getWindow();
    float speed = 70.f;

    for (int i = 0; i < enemies.size(); i++) {
        sf::Vector2f pos = enemies[i]->getPosition();

        if (pos.x <= 0 + 40.f) direction = 1;
        if (pos.x >= window.getSize().x - 40.f) direction = -1;

        pos.x += speed * deltaTime * direction;
        enemies[i]->setPosition(pos);
    }
}