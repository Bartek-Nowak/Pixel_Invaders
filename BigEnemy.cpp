#include "BigEnemy.h"
#include <string>

BigEnemy::BigEnemy() {
	std::string fileName = "enemy-big.png";
	for (int i = 0; i < 2; ++i) {
		sf::IntRect frame({ 32 * i, 0 }, { 32, 32 });

		animation.addFrame(frame);
	}

	animation.setFrameTime(0.1f);
	setSize({ 4, 4 });
	setTexture(fileName, animation.getCurrentFrame());
	health = 400;
	score = 60;
}

BigEnemy::~BigEnemy() {}

void BigEnemy::render() {}

void BigEnemy::update() {
	Enemy::update();
	animation.update();

	if (sprite) {
		sprite->setTextureRect(animation.getCurrentFrame());
		sprite->setPosition(this->getPosition());
		sprite->setScale(this->getSize());
	}
}