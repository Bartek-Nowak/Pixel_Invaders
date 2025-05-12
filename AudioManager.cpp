#include "AudioManager.h"
#include "GameEngineConfig.h"
#include <iostream>

AudioManager::AudioManager() {}

AudioManager* AudioManager::instance = 0;

AudioManager* AudioManager::getInstance() {
    if (instance == 0) {
        instance = new AudioManager();
    }
    return instance;
}

AudioManager::~AudioManager() {
    std::map<std::string, sf::SoundBuffer*>::iterator itb;
    for (itb = soundBuffers.begin(); itb != soundBuffers.end(); ++itb) {
        delete itb->second;
    }
    std::map<std::string, sf::Music*>::iterator itm;
    for (itm = musics.begin(); itm != musics.end(); ++itm) {
        delete itm->second;
    }
}

bool AudioManager::loadSoundEffect(const std::string& name, const std::string& filename) {
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    if (!buffer->loadFromFile(GameEngineConfig::AUDIO_PATH + filename)) {
        delete buffer;
        return false;
    }
    soundBuffers[name] = buffer;
    return true;
}

void AudioManager::playSoundEffect(const std::string& name) {
    auto it = soundBuffers.find(name);
    if (it == soundBuffers.end()) return;

    sf::Sound* sound = new sf::Sound(*it->second);
    sound->setVolume(20);
    sound->play();
    sounds.push_back(sound);
}

bool AudioManager::loadMusic(const std::string& name, const std::string& filename) {
    sf::Music* music = new sf::Music();
    if (!music->openFromFile(GameEngineConfig::AUDIO_PATH + filename)) {
        delete music;
        return false;
    }
    musics[name] = music;
    return true;
}

void AudioManager::playMusic(const std::string& name, bool loop) {
    stopMusic();
    std::map<std::string, sf::Music*>::iterator it = musics.find(name);
    if (it == musics.end()) return;

    if (currentMusic != NULL && currentMusic != it->second) {
        currentMusic->stop();
    }
    currentMusic = it->second;
    currentMusic->setLooping(loop);
    currentMusic->play();
}

void AudioManager::stopMusic() {
    if (currentMusic != NULL) {
        currentMusic->stop();
        currentMusic = NULL;
    }
}

void AudioManager::update() {
    std::list<sf::Sound*>::iterator it = sounds.begin();
    while (it != sounds.end()) {
        if ((*it)->getStatus() == sf::Sound::Status::Stopped) {
            delete* it;
            it = sounds.erase(it);
        }
        else {
            ++it;
        }
    }
}
