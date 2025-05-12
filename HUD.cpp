#include "HUD.h"
#include <iostream>
#include "GameEngine.h"
#include "TextContainer.h"
#include "Player.h";
#include "HealthNumber.h";

HUD* HUD::instance = 0;

HUD::HUD() {
    scoreText = new TextContainer("PressStart2P", std::to_string(this->score));
    scoreText->setPosition(10.f, 10.f);
    healt = Player::getInstance()->getHealth();
    healthNumber = new HealthNumber(healt);
}

HUD::~HUD() {
    delete scoreText;
}

HUD* HUD::getInstance() {
    if (instance == 0) {
        instance = new HUD();
    }
    return instance;
}

void HUD::draw() {
    scoreText->draw();
    healthNumber->draw();
}

void HUD::addToScore(int score) {
    this->score += score;

    if (scoreText) {
        scoreText->setText(std::to_string(this->score));
    }
};

void HUD::removeHeart() {
    healthNumber->removeHeart();
};

int HUD::getScore() {
    return this->score;
}