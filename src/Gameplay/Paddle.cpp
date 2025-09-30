//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Paddle.h"

namespace N_Gameplay {
    Paddle::Paddle(float p_position_x, float p_position_y) {
        paddle_sprite_.setSize({paddle_width_, paddle_height_});
        paddle_sprite_.setPosition({p_position_x, p_position_y});
    }

    Paddle::~Paddle() {
    }

    void Paddle::update() {
    }

    void Paddle::render(sf::RenderWindow *p_window) {
        p_window->draw(paddle_sprite_);
    }
} // N_Gameplay