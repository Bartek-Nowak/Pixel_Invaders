#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngineConfig.h"
#include <string>

namespace GameWindow {
	sf::RenderWindow createWindow(std::string windowName = GameEngineConfig::WINDOW_TITLE);
}
