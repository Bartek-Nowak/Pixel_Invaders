#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class AudioManager {
public:
    static AudioManager* getInstance();

    AudioManager();
    ~AudioManager();
    bool loadSoundEffect(const std::string& name, const std::string& filename);
    void playSoundEffect(const std::string& name);
    bool loadMusic(const std::string& name, const std::string& filename);
    void playMusic(const std::string& name, bool loop);
    void stopMusic();
    void update();
private:
    std::map<std::string, sf::SoundBuffer*> soundBuffers;
    std::list<sf::Sound*> sounds;
    std::map<std::string, sf::Music*> musics;
    sf::Music* currentMusic;
    static AudioManager* instance;
};
