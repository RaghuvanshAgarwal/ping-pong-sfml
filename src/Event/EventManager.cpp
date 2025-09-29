//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Event/EventManager.h"

#include <iostream>

#include "SFML/Graphics.hpp"

namespace N_Event {
    void EventManager::pollEvents(sf::RenderWindow *p_window) {
        while (const std::optional event = p_window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                p_window->close();
            }

            if (isKeyPressed(sf::Keyboard::Key::Escape)) {
                p_window->close();
            }

            if (isLeftMouseButtonPressed()) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(*p_window);
                std::cout << mouse_pos.x << ", " << mouse_pos.y << std::endl;
            }
        }

    }
    bool EventManager::isKeyPressed(sf::Keyboard::Key p_key) {
        return sf::Keyboard::isKeyPressed(p_key);
    }

    bool EventManager::isLeftMouseButtonPressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    }
}
