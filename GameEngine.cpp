#include "GameEngine.h"
#include "GameWindow.h"
#include "GameEngineConfig.h"
#include "LevelManager.h"
#include "AudioManager.h"
#include "Player.h"
#include "LoaderManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameEngine::GameEngine() {
}

GameEngine& GameEngine::getInstance() {
	static GameEngine instance;
	return instance;
}

void GameEngine::init() {
	std::cout << "Inicjalizacja gry..." << std::endl;
	LoaderManager::getInstance()->showLoadingScreen();

	LoaderManager::getInstance()->loadAllAssets();

	this->levelManager = LevelManager::getSingleton();
	this->audioManager = AudioManager::getInstance();

	setScale();
}

void GameEngine::render() {
	if (levelManager != nullptr) {
		levelManager->drawLevel();
	}
	for (Explosion* explosion : explosions) {
		explosion->draw();
	}
}

void GameEngine::update() {
	if (levelManager != nullptr) {
		this->levelManager->updateLevel();
	}
	for (int i = 0; i < explosions.size(); ++i) {
		explosions[i]->update();
		if (explosions[i]->isFinished()) {
			delete explosions[i];
			explosions.erase(explosions.begin() + i);
			--i;
		}
	}
}

void GameEngine::start() {
	this->window = GameWindow::createWindow();

	window.setKeyRepeatEnabled(true);

	sf::View view = window.getDefaultView();

	this->init();

	while (window.isOpen()) {
		deltaTime = deltaClock.restart().asSeconds();

		while (const std::optional event = window.pollEvent()) {

			if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();

			if (const auto* resized = event->getIf<sf::Event::Resized>()) {
				view.setSize({
					static_cast<float>(resized->size.x),
					static_cast<float>(resized->size.y)
					});
				view.setCenter({ view.getSize().x / 2.f, view.getSize().y / 2.f });
				window.setView(view);
				setScale();
			}	

		}

		this->update();

		window.clear();

		this->render();

		window.display();
	}

}


sf::RenderWindow& GameEngine::getWindow() {
	return this->window;
}

float GameEngine::getScale() const {
	if (windowScale == -1) {
		return 1.f;
	}
	return this->windowScale;
}

void GameEngine::setScale() {
	if (!this->window.isOpen()) {
		this->windowScale = 1.f;
		return;
	}

	sf::Vector2u size = this->window.getSize();
	/*float ratio = (float)this->window.getSize().x / this->window.getSize().y;
	float targetRatio = (float)GameEngineConfig::WINDOW_WIDTH / GameEngineConfig::WINDOW_HEIGHT;
	std::cout << ratio << " " << targetRatio << std::endl;*/
	this->windowScale = 1;
	return;
	//if (ratio > targetRatio) {
	//	std::cout << "A: ";
	//	//std::cout << targetRatio  << " " << "A" << " " << this->window.getSize().y << " " << GameEngineConfig::WINDOW_HEIGHT << " " << (float)this->window.getSize().y / GameEngineConfig::WINDOW_HEIGHT << std::endl;
	//	this->windowScale = (float)this->window.getSize().y / GameEngineConfig::WINDOW_HEIGHT;
	//	std::cout << this->windowScale << std::endl;
	//	return;
	//}
	//	std::cout << "B: ";
	//	this->windowScale = (float)this->window.getSize().x / GameEngineConfig::WINDOW_WIDTH;
	//	std::cout << this->windowScale << std::endl;
}

float GameEngine::getDeltaTime() const {
	return deltaTime;
}

void GameEngine::showCursor(bool value) {
	this->window.setMouseCursorVisible(value);
}

void GameEngine::addExplosion(Explosion* explosion) {
	explosions.push_back(explosion);
}