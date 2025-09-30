//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Ball.h"

namespace N_Gameplay {
    void Ball::loadTexture() {
        if (!texture_.loadFromFile(texture_path_)) {
            throw std::runtime_error("Failed to load texture from " + texture_path_);
        }
    }

    void Ball::initializeVariables() {
        sprite_ = new sf::Sprite(texture_);
        sprite_->setScale({scale_x, scale_y});
        sprite_->setPosition({position_x_, position_y_});
    }

    Ball::Ball() {
        loadTexture();
        initializeVariables();
    }

    Ball::~Ball() {
        delete sprite_;
    }

    void Ball::update() {
    }

    void Ball::render(sf::RenderWindow *p_window) {
        p_window->draw(*sprite_);
    }
} // N_Gameplay