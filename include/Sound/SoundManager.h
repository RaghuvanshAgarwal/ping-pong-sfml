//
// Created by Raghuvansh Agarwal on 07/10/25.
//

#ifndef CMAKESFMLPROJECT_SOUNDMANAGER_H
#define CMAKESFMLPROJECT_SOUNDMANAGER_H
#include <SFML/Audio.hpp>

namespace N_Sound {

    enum class SOUND_TYPE {
        Bounce,
    };

    class SoundManager {
        sf::Music* background_music_ = nullptr;
        sf::Sound* sound_effect_ = nullptr;
        sf::SoundBuffer* ball_bounce_ = nullptr;

        float bgm_volume_{};
        std::string bgm_file_path_;
        std::string ball_bounce_file_path_ = std::string(PROJECT_ROOT) + "Assets/Sounds/Ball_Bounce.wav";
        void loadSoundFromFile();
        SoundManager();
    public:
        static SoundManager& getInstance();
        SoundManager(const SoundManager&) = delete;
        SoundManager& operator=(const SoundManager&) = delete;
        void playSoundEffect(SOUND_TYPE p_type) const;
        void playBackgroundMusic();
    };
} // N_Sound

#endif //CMAKESFMLPROJECT_SOUNDMANAGER_H