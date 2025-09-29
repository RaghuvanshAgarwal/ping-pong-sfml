//
// Created by Raghuvansh Agarwal on 27/09/25.
//

#include "../../include/Core/GameWindowManager.h"

namespace N_Core {
    void GameWindowManager::initialize() {
        game_window = new sf::RenderWindow(sf::VideoMode({game_window_width, game_window_height}), game_title);
        game_window->setFramerateLimit(60);
    }

    bool GameWindowManager::isGameRunning() const {
        return game_window->isOpen();
    }



    sf::RenderWindow *GameWindowManager::getGameWindow() const {
        return game_window;
    }

    void GameWindowManager::clearGameWindow() {
        game_window->clear();
    }

    void GameWindowManager::renderGameWindow() {
        game_window->display();
    }

    GameWindowManager::~GameWindowManager() {
        delete game_window;
    }
}
