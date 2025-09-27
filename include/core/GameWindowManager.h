//
// Created by Raghuvansh Agarwal on 27/09/25.
//

#ifndef CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H
#define CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H

#include <SFML/Graphics.hpp>

namespace Core {
    class GameWindowManager {
        int game_window_height = 720;
        int game_window_width = 1280;
        std::string game_title = "[SFML] Ping Pong";
        sf::RenderWindow* game_window = nullptr;

        void create_game_window() const;
    public:
        void initialize();
        sf::RenderWindow* get_game_window() const ;
        bool is_game_running() const;
        void render();
    };
}


#endif //CMAKESFMLPROJECT_GAMEWINDOWMANAGER_H