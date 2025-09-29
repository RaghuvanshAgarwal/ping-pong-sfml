//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Ball.h"

namespace N_Gameplay {
    Ball::Ball() {
        ball_sprite_.setRadius(radius_);
        ball_sprite_.setPosition({position_x_, position_y_});
    }

    Ball::~Ball() {
    }

    void Ball::update() {
    }

    void Ball::render(sf::RenderWindow *p_window) {
        p_window->draw(ball_sprite_);
    }
} // N_Gameplay