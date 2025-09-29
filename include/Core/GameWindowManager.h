//
// Created by Raghuvansh Agarwal on 27/09/25.
//

#ifndef CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H
#define CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H

#include <SFML/Graphics.hpp>

#include "../Event/EventManager.h"

namespace Core {
    class GameWindowManager {
        unsigned game_window_height = 720u;
        unsigned game_window_width = 1280u;
        std::string game_title = "[SFML] Ping Pong";
        sf::RenderWindow* game_window = nullptr;
    public:
        void initialize();
        sf::RenderWindow* get_game_window() const ;
        bool is_game_running() const;
        void render();

        ~GameWindowManager();

    };
}


#endif //CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H