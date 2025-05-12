#include "Player.h"
#include "GameEngine.h"
#include "AudioManager.h"
#include "HUD.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Player* Player::instance = nullptr;

Player* Player::getInstance() {
	if (instance == nullptr) {
		instance = new Player();
	}
	return instance;
}

Player::Player() {
	std::string fileName = "ship.png";

	for (int i = 0; i < 2; ++i) {
		sf::IntRect frame({ 32, 24 * i }, { 16, 24 });

		animation.addFrame(frame);
	}
	for (Bullet* bullet : bullets) {
		bullet->draw();
	}

	sf::RenderWindow& window = GameEngine::getInstance().getWindow();

	animation.setFrameTime(0.1f);
	setSize({ 4, 4 });
	setPosition({ (float)window.getSize().x / 2.f, (float)window.getSize().y});
	setTexture(fileName, animation.getCurrentFrame());
}


Player::~Player() {
	for (Bullet* bullet : bullets) {
		delete bullet;
	}
	bullets.clear();
}

void Player::render() {}

void Player::update() {
	animation.update();
	move();
	shot();
	if (sprite) {
		sprite->setTextureRect(animation.getCurrentFrame());
		sprite->setPosition(this->getPosition());
		sprite->setScale(this->getSize());
	}

	float deltaTime = GameEngine::getInstance().getDeltaTime();

	if (invincibilityTime > 0.f) {
		invincibilityTime -= deltaTime;
		blinkTimer += deltaTime;

		if (blinkTimer >= blinkInterval) {
			visible = !visible;
			blinkTimer = 0.f;
		}

		if (invincibilityTime <= 0.f) {
			visible = true;
			recentlyHit = false;
		}
	}


	for (auto it = bullets.begin(); it != bullets.end();) {
		Bullet* bullet = *it;

		if (bullet->isOffScreen()) {
			delete bullet;
			it = bullets.erase(it);
		}
		else {
			++it;
		}
	}

	for (Bullet* bullet : bullets) {
		bullet->update();
	}
}

float updateVelocity(float currentVelocity, float targetVelocity, float deltaTime, float acceleration, float deceleration) {
	float diff = targetVelocity - currentVelocity;
	float accel = (std::abs(targetVelocity) > std::abs(currentVelocity)) ? acceleration : deceleration;

	float deltaV = accel * deltaTime * (diff > 0 ? 1.f : -1.f);

	if (std::abs(deltaV) > std::abs(diff)) {
		return targetVelocity;
	}

	return currentVelocity + deltaV;
}

void Player::move() {
	sf::Vector2f direction(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) direction.x -= 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction.x += 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) direction.y -= 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) direction.y += 1.f;

	if (direction.x != 0.f || direction.y != 0.f) {
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x /= length;
		direction.y /= length;
	}

	float targetSpeedX = direction.x * maxSpeed;
	float targetSpeedY = direction.y * maxSpeed;

	float deltaTime = GameEngine::getInstance().getDeltaTime();

	velocityX = updateVelocity(velocityX, targetSpeedX, deltaTime, acceleration, deceleration);
	velocityY = updateVelocity(velocityY, targetSpeedY, deltaTime, acceleration, deceleration);

	sf::Vector2f pos = getPosition();
	pos.x += velocityX * deltaTime;
	pos.y += velocityY * deltaTime;


	sf::Vector2u windowSize = GameEngine::getInstance().getWindow().getSize();

	float halfWidth = (sprite ? sprite->getGlobalBounds().size.x / 2.f : 0.f);
	float halfHeight = (sprite ? sprite->getGlobalBounds().size.y / 2.f : 0.f);

	if (pos.x <= 0.f + halfWidth) {
		pos.x = 0.f + halfWidth;
		velocityX = 0;
	}
	if (pos.y <= 0.f + halfHeight) {
		pos.y = 0.f + halfHeight;
		velocityY = 0;
	}
	if (pos.x >= windowSize.x - halfWidth) {
		pos.x = windowSize.x - halfWidth;
		velocityX = 0;
	}
	if (pos.y >= windowSize.y - halfHeight) {
		pos.y = windowSize.y - halfHeight;
		velocityY = 0;
	}

	setPosition(pos);
}

void Player::shot() {
	float deltaTime = GameEngine::getInstance().getDeltaTime();
	shootTimer += deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		if (shootTimer >= shootCooldown) {
			AudioManager::getInstance()->playSoundEffect("shot");
			sf::Vector2f bulletPos = getPosition();
			bulletPos.x += getSize().x / 2.f;
			Bullet* bullet = new Bullet(bulletPos, -800.f, { 14, 18 }, { 6, 12 });
			bullets.push_back(bullet);
			shootTimer = 0.f;
		}
	}

}

void Player::draw() {
	for (Bullet* bullet : bullets) {
		bullet->draw();
	}

	if (visible) {
		Entity::draw();
	}
}


std::vector<Bullet*>& Player::getBullets() {
	return bullets;
}

void Player::takeDamage() {
	if (invincibilityTime > 0.f) return; // nieœmiertelnoœæ aktywna
	HUD::getInstance()->removeHeart();
	// wybuch – mo¿esz dodaæ globalny manager lub przekazaæ przez callback (np. GameEngine::getInstance().spawnExplosion)
	Explosion* explosion = new Explosion(getPosition());
	GameEngine::getInstance().addExplosion(explosion); // musisz dodaæ obs³ugê, patrz ni¿ej

	health--;
	invincibilityTime = maxInvincibilityTime;
	recentlyHit = true;

	sf::RenderWindow& window = GameEngine::getInstance().getWindow();
	setPosition({ window.getSize().x / 2.f, window.getSize().y - getSize().y });
	velocityX = 0.f;
	velocityY = 0.f;
}


int Player::getHealth() {
	return this->health;
}

bool Player::isDead() {
	return this->health <= 0;
}