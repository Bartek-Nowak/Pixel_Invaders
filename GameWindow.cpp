#include "GameWindow.h"
#include "GameEngineConfig.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

namespace GameWindow {

	sf::RenderWindow createWindow(std::string windowName) {
		sf::RenderWindow window(sf::VideoMode({ GameEngineConfig::WINDOW_WIDTH, GameEngineConfig::WINDOW_HEIGHT }), windowName, sf::Style::Default, sf::State::Fullscreen);
		window.setFramerateLimit(60);

		return window;
	}
}
