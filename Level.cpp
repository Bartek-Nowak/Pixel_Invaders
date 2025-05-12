#include "Level.h"
#include "Enemy.h"
#include "GameEngine.h"
#include "AudioManager.h"
#include "LevelManager.h"

Level::Level() {}

Level::~Level() {
    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    for (Explosion* explosion : explosions) {
        delete explosion;
    }
    explosions.clear();
}

void Level::render() {}

void Level::unmount() {
    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();
}

void Level::update() {
    for (Enemy* enemy : enemies) {
        enemy->update();
    }

    if (playerDead) {
        deathTimer += GameEngine::getInstance().getDeltaTime();
        if (deathTimer >= deathDelay) {
            LevelManager::getSingleton()->nextLevel();
        }
        return;
    }
    else {
    
        if (player) {
            player->update();

            auto& bullets = player->getBullets();

            for (int i = (int)bullets.size() - 1; i >= 0; i--) {
                for (int j = 0; j < enemies.size(); j++) {
                    if (bullets[i]->getBounds().findIntersection(enemies[j]->getBounds())) {
                        enemies[j]->takeDamage(bullets[i]->getDamage());

                        delete bullets[i];
                        bullets.erase(bullets.begin() + i);


                        if (enemies[j]->isDead()) {
                            HUD->addToScore(enemies[j]->getScore());
                            AudioManager::getInstance()->playSoundEffect("damage");

                            Explosion* explosion = new Explosion(enemies[j]->getPosition());
                            explosions.push_back(explosion);

                            delete enemies[j];
                            enemies.erase(enemies.begin() + j);
                        }

                        break;
                    }
                }
            }

            for (int i = 0; i < enemies.size(); i++) {
                auto& bullets = enemies[i]->getBullets();

                if (enemies[i]->getBounds().findIntersection(player->getBounds())) {
                    player->takeDamage();
                    if (player->isDead() && !playerDead) {
                        playerDead = true;
                        deathTimer = 0.f;
                    }
                }

                for (int j = (int)bullets.size() - 1; j >= 0; j--) {
                    if (bullets[j]->getBounds().findIntersection(player->getBounds())) {
                        player->takeDamage();
                        if (player->isDead() && !playerDead) {
                            playerDead = true;
                            deathTimer = 0.f;
                        }
                        delete bullets[j];
                        bullets.erase(bullets.begin() + j);
                    }
                }
            }

            if (deathTimer >= deathDelay) {
                LevelManager::getSingleton()->nextLevel();
            }

            if (enemies.size() == 0) LevelManager::getSingleton()->nextLevel();

 
        }
    
    }

    for (int i = 0; i < explosions.size(); ++i) {
        explosions[i]->update();
        if (explosions[i]->isFinished()) {
            delete explosions[i];
            explosions.erase(explosions.begin() + i);
            --i;
        }
    }


}

void Level::draw() {
    if (background) {
        background->draw();
    }

    for (Explosion* explosion : explosions) {
        explosion->draw();
    }

    for (Enemy* enemy : enemies) {
        enemy->draw();
    }


    if (player && !playerDead) {
        player->draw();
    }

    if (HUD && !playerDead) {
        HUD->draw();
        }

}
