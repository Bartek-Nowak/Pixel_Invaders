#include "SmallEnemy.h"
#include <string>

SmallEnemy::SmallEnemy() {
	std::string fileName = "enemy-small.png";
	for (int i = 0; i < 2; ++i) {
		sf::IntRect frame({ 16 * i, 0 }, { 16, 16 });

		animation.addFrame(frame);
	}

	animation.setFrameTime(0.1f);
	setSize({ 4, 4 });
	setTexture(fileName, animation.getCurrentFrame());
}

SmallEnemy::~SmallEnemy() {
}

void SmallEnemy::render() {}

void SmallEnemy::update() {
	Enemy::update();
	animation.update();

	if (sprite) {
		sprite->setTextureRect(animation.getCurrentFrame());
		sprite->setPosition(this->getPosition());
		sprite->setScale(this->getSize());
	}
}
