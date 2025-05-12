#include "LevelManager.h"
#include "LevelFactory.h"
#include "Level.h"
#include "AudioManager.h"
#include <vector>
#include <iostream>

void LevelManager::changeLevel(int index) {
	if (index >= 0 && index < levelsList.size()) {
		this->currentLevel = levelsList[index];
		this->currentLevelIndex = index;
		std::cout << "Zmieniono poziom na indeks: " << currentLevel->music << std::endl;

		AudioManager::getInstance()->playMusic(currentLevel->music, true);
	}
	else {
		std::cout << "Nieprawid³owy indeks poziomu: " << index << std::endl;
	}
}

void LevelManager::nextLevel() {
	changeLevel(this->currentLevelIndex + 1);
}

void LevelManager::registerLevels(std::vector< Level* > levelList) {
	for (Level* level : levelList) {
		if (level != nullptr) {
			levelsList.push_back(level);
		}
	}
}

void LevelManager::registerDefaultLevels() {
	Level* level = LevelFactory::createLevel(1);
	if (level != nullptr) {
		levelsList.push_back(level);
		currentLevelIndex = 0;
		currentLevel = level;
	}
}


void LevelManager::deleteLevel(int index) {
	if (index >= 0 && index < levelsList.size()) {
		delete levelsList[index];
		levelsList.erase(levelsList.begin() + index);

		if (levelsList.empty()) {
			currentLevel = nullptr;
			currentLevelIndex = -1;
		}
		else {
			if (index == currentLevelIndex) {
				currentLevelIndex = 0;
				currentLevel = levelsList[0];
			}
			else if (index < currentLevelIndex) {
				currentLevelIndex -= 1;
			}
		}
	}
	else {
		std::cout << "Nieprawid³owy indeks do usuniêcia: " << index << std::endl;
	}
}

void LevelManager::drawLevel() {
	if (currentLevel != nullptr) {
		currentLevel->draw();
	}
}

void LevelManager::updateLevel() {
	if (currentLevel != nullptr) currentLevel->update();
}

LevelManager* LevelManager::instance = 0;

LevelManager* LevelManager::getSingleton() {
	if (instance == 0) {
		instance = new LevelManager();
	}
	return instance;
}

LevelManager::LevelManager() {
	currentLevel = nullptr;
	currentLevelIndex = -1;

	std::vector<Level*> levels;
	levels.push_back(LevelFactory::createLevel(1)); // Menu
	levels.push_back(LevelFactory::createLevel(2)); // Level2
	levels.push_back(LevelFactory::createLevel(3)); // Game Over
	registerLevels(levels);

	if (!levelsList.empty()) {
		currentLevel = levelsList[0];
		currentLevelIndex = 0;
		AudioManager::getInstance()->playMusic(currentLevel->music, true);
	}
}

LevelManager::~LevelManager() {
	for (int i = 0; i < levelsList.size(); i++) {
		delete levelsList[i];
	}
	levelsList.clear();
}
