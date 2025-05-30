#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation();

    // Dodaj klatk� animacji (fragment tekstury)
    void addFrame(const sf::IntRect& frame);

    // Ustaw pr�dko�� animacji (czas trwania jednej klatki w sekundach)
    void setFrameTime(float time);

    // Aktualizuj animacj� na podstawie deltaTime (czas od ostatniej aktualizacji)
    void update();

    // Zwr�� aktualny prostok�t (klatk�) animacji do ustawienia w sprite
    sf::IntRect getCurrentFrame() const;

    // Zresetuj animacj� (do pierwszej klatki)
    void reset();

private:
    std::vector<sf::IntRect> frames; // klatki animacji (prostok�ty w teksturze)
    float frameTime;                 // czas trwania pojedynczej klatki
    float elapsedTime;               // czas od ostatniej zmiany klatki
    size_t currentFrameIndex;       // aktualny indeks klatki
};

