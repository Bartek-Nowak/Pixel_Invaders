#pragma once
#include "TextContainer.h"
#include "HealthNumber.h"
#include <vector>

class HUD {
public:
    static HUD* getInstance();
	void draw();
    void addToScore(int score);
    void removeHeart();
    int getScore();
private:
    int score = 0;
    HUD();
    ~HUD();
    static HUD* instance;
protected:
	TextContainer* scoreText;
    HealthNumber* healthNumber;
    int healt;
};
