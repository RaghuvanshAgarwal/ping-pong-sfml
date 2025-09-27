//
// Created by Raghuvansh Agarwal on 27/09/25.
//

#include "../../include/core/GameWindowManager.h"

namespace Core {

    void GameWindowManager::initialize() {
        game_window = new sf::RenderWindow();
        create_game_window();
    }

    void GameWindowManager::create_game_window() const {
        const auto window_size = sf::Vector2u(game_window_width, game_window_height);
        game_window->create(sf::VideoMode(window_size), game_title);
    }

    bool GameWindowManager::is_game_running() const {
        return game_window->isOpen();
    }

    sf::RenderWindow* GameWindowManager::get_game_window() const {
        return game_window;
    }

    void GameWindowManager::render() {
        // TODO: Implement in future
    }

}