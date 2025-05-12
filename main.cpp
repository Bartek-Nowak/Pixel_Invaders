#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        window.draw(shape);
        // Update the window
        window.display();
    }
}