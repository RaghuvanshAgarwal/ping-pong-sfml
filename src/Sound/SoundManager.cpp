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

    SoundManager::SoundManager() {
        ball_bounce_ = new sf::SoundBuffer();
        loadSoundFromFile();
        sound_effect_ = new sf::Sound(*ball_bounce_);
    }

    SoundManager & SoundManager::getInstance() {
        static SoundManager instance;
        return instance;
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

    void SoundManager::playBackgroundMusic() {
    }
} // N_Sound