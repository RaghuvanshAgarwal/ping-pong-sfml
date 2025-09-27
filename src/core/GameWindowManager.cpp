//
// Created by Raghuvansh Agarwal on 27/09/25.
//

#include "../../include/core/GameWindowManager.h"

namespace Core {

    void GameWindowManager::initialize() {
        game_window = new sf::RenderWindow(sf::VideoMode({game_window_width,game_window_height}),game_title);
        game_window->setFramerateLimit(60);
    }

    bool GameWindowManager::is_game_running() const {
        return game_window->isOpen();
    }

    sf::RenderWindow* GameWindowManager::get_game_window() const {
        return game_window;
    }

    void GameWindowManager::take_input() {
        while (const std::optional event = game_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                game_window->close();
            }
        }
    }

    void GameWindowManager::render() {
        game_window->clear(sf::Color(200, 50, 50, 255));
        game_window->display();
    }

    GameWindowManager::~GameWindowManager() {
        delete game_window;
    }
}
