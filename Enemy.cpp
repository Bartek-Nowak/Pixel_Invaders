#include "Entity.h"
#include "Enemy.h"
#include "GameEngine.h"
#include "Bullet.h"
#include <iostream>
#include <iostream>
#include <random>

Enemy::Enemy() {
	std::random_device rd;             
	std::mt19937 gen(rd());                  
	std::uniform_int_distribution<> dist(1, 5); 

	shootCooldown = dist(gen);
}

Enemy::~Enemy() {

}

void Enemy::takeDamage(float damage) {
    health -= damage;
}

float Enemy::getHealth() {
    return health;
}

bool Enemy::isDead() {
    return health <= 0.f;
}

int Enemy::getScore() {
    return score;
}

void Enemy::shot() {
	float deltaTime = GameEngine::getInstance().getDeltaTime();
	shootTimer += deltaTime;
		if (shootTimer >= shootCooldown) {
			sf::Vector2f bulletPos = getPosition();
			bulletPos.x += getSize().x / 2.f;
			Bullet* bullet = new Bullet(bulletPos, 500.f, {14, 7}, { 6, 6 });
			bullets.push_back(bullet);
			shootTimer = 0.f;
		}
}

void Enemy::update() {
	shot();
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

void Enemy::draw() {
	
	for (Bullet* bullet : bullets) {
		bullet->draw();
	}

	Entity::draw();
}

std::vector<Bullet*>& Enemy::getBullets() {
	return bullets;
}
