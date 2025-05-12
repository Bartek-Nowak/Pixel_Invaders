#pragma once
#include <SFML/Graphics.hpp>
#include "UiComponent.h"
#include "TextContainer.h"
#include <string>
#include <functional>

class Button : public UiComponent {
public:
    Button(std::string label);

    using Callback = std::function<void()>;

    void setCallback(Callback cb) { onClick = cb; }

    void draw() override;
    sf::Vector2f getSize();
    void handleEvent();
    void update();

private:
    bool isMouseOver();
    Callback onClick;
    TextContainer* label;
};
