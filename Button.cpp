#include "Button.h"
#include "TextContainer.h"
#include "GameEngine.h"
#include <SFML/Graphics.hpp>
#include <string>

Button::Button(std::string label) {
	this->label = new TextContainer("PressStart2P", label);
	this->label->setPosition(getPosition().x, getPosition().y);
}

void Button::draw() {
	label->setPosition(getPosition().x, getPosition().y);
	label->draw();
}

sf::Vector2f Button::getSize() {
	return this->label->getSize();
}

bool Button::isMouseOver() {
	sf::RenderWindow& window = GameEngine::getInstance().getWindow();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect bounds(getPosition(), getSize());
	return bounds.contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::handleEvent() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isMouseOver() && onClick) onClick();
}

void Button::update() {
	handleEvent();
}