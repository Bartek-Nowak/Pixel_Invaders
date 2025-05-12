#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation();

    // Dodaj klatkê animacji (fragment tekstury)
    void addFrame(const sf::IntRect& frame);

    // Ustaw prêdkoœæ animacji (czas trwania jednej klatki w sekundach)
    void setFrameTime(float time);

    // Aktualizuj animacjê na podstawie deltaTime (czas od ostatniej aktualizacji)
    void update();

    // Zwróæ aktualny prostok¹t (klatkê) animacji do ustawienia w sprite
    sf::IntRect getCurrentFrame() const;

    // Zresetuj animacjê (do pierwszej klatki)
    void reset();

private:
    std::vector<sf::IntRect> frames; // klatki animacji (prostok¹ty w teksturze)
    float frameTime;                 // czas trwania pojedynczej klatki
    float elapsedTime;               // czas od ostatniej zmiany klatki
    size_t currentFrameIndex;       // aktualny indeks klatki
};

