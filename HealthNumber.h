#pragma once

#include "UiComponent.h"
#include "SpriteComponent.h"
#include <vector>

class HealthNumber : public UiComponent {
public:
	HealthNumber(int healthNumber);
	void draw() override;
	void removeHeart();
private:
	int health;
	std::vector< SpriteComponent* > hearts;
};
