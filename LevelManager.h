#pragma once
#include <vector>
#include "Level.h"

class LevelManager
{
public:
	static LevelManager* getSingleton();

	void nextLevel();

	void registerLevels(std::vector< Level* >);
	void registerDefaultLevels();
	void deleteLevel(int id);
	void drawLevel();
	void updateLevel();

private:
	LevelManager();
	~LevelManager();
	LevelManager(const LevelManager&);
	LevelManager& operator=(const LevelManager&);
	void changeLevel(int index);
	Level* currentLevel;
	int currentLevelIndex;
	std::vector< Level* > levelsList;
	static LevelManager* instance;
};
