#include "MediumEnemy.h"
#include <string>

MediumEnemy::MediumEnemy() {
	std::string fileName = "enemy-medium.png";
	for (int i = 0; i < 2; ++i) {
		sf::IntRect frame({ 32 * i, 0 }, { 32, 16 });

		animation.addFrame(frame);
	}

	animation.setFrameTime(0.1f);
	setSize({ 4, 4 });
	setTexture(fileName, animation.getCurrentFrame());
	health = 250;
	score = 35;
}

MediumEnemy::~MediumEnemy() {}

void MediumEnemy::render() {}

void MediumEnemy::update() {
	Enemy::update();
	animation.update();

	if (sprite) {
		sprite->setTextureRect(animation.getCurrentFrame());
		sprite->setPosition(this->getPosition());
		sprite->setScale(this->getSize());
	}
}