#include "Animation.h"
#include "GameEngine.h"

Animation::Animation(): frameTime(0.1f), elapsedTime(0.0f), currentFrameIndex(0) {}

void Animation::addFrame(const sf::IntRect& frame) {
    frames.push_back(frame);
}

void Animation::setFrameTime(float time) {
    frameTime = time;
}

void Animation::update() {
    if (frames.empty()) return;

    // Pobierz deltaTime z GameEngine singleton
    float deltaTime = GameEngine::getInstance().getDeltaTime();

    elapsedTime += deltaTime;

    while (elapsedTime >= frameTime) {
        elapsedTime -= frameTime;
        currentFrameIndex++;
        if (currentFrameIndex >= frames.size())
            currentFrameIndex = 0; // zapêtlenie animacji
    }
}

sf::IntRect Animation::getCurrentFrame() const {
    if (frames.empty()) return sf::IntRect();
    return frames[currentFrameIndex];
}

void Animation::reset() {
    currentFrameIndex = 0;
    elapsedTime = 0;
}
