#pragma once
#include <SFML/Graphics.hpp>

class GameComponent {
public:
    GameComponent();
    ~GameComponent();
    
    virtual void render() = 0;
    virtual void update() = 0;

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getSize();
	sf::Vector2f getPosition();

protected:
	sf::Vector2f position;
	sf::Vector2f size;
};

