//
// Created by Raghuvansh Agarwal on 07/10/25.
//

#include "../../include/Sound/SoundManager.h"

namespace N_Sound {
    void SoundManager::loadSoundFromFile() {
        if (!ball_bounce_->loadFromFile(ball_bounce_file_path_)) {
            throw std::runtime_error("SoundManager::loadSoundFromFile: Failed to load ball_bounce");
        }
    }

    void SoundManager::loadBackgroundMusic() {
        if (!background_music_->openFromFile(bgm_file_path_)) {
            throw std::runtime_error("SoundManager::loadBackgroundMusic: Failed to load background music");
        }
    }

    SoundManager::SoundManager() {
        ball_bounce_ = new sf::SoundBuffer();
        background_music_ = new sf::Music();
        loadSoundFromFile();
        loadBackgroundMusic();
        sound_effect_ = new sf::Sound(*ball_bounce_);
    }

    SoundManager & SoundManager::getInstance() {
        static SoundManager instance;
        return instance;
    }

    SoundManager::~SoundManager() {
        delete ball_bounce_;
        delete background_music_;
        delete sound_effect_;
    }

    void SoundManager::playSoundEffect(const SOUND_TYPE p_type) const {
        switch (p_type) {
            case SOUND_TYPE::Bounce:
                sound_effect_->setBuffer(*ball_bounce_);
                sound_effect_->play();
                break;
            default:
                throw std::runtime_error("SoundManager::playSoundEffect: Invalid type");
        }
    }

    void SoundManager::playBackgroundMusic() const {
        background_music_->setVolume(bgm_volume_);
        background_music_->setLooping(true);
        background_music_->play();
    }
} // N_Sound