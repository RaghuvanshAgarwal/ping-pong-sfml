//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Paddle.h"

namespace N_Gameplay {
    Paddle::Paddle(float p_position_x, float p_position_y) {
        if (!texture_.loadFromFile(std::string(PROJECT_ROOT) +"/Assets/Textures/Paddle.png")) {
            throw std::runtime_error("Failed to load paddle texture");
        }
        sprite_ = new sf::Sprite(texture_);
        sprite_->setScale({paddle_height_ / texture_.getSize().x, paddle_width_ / texture_.getSize().y});
        sprite_->setRotation(sf::Literals::operator ""_deg(90.0l));
        sprite_->setOrigin({static_cast<float>(texture_.getSize().x/2),static_cast<float>(texture_.getSize().y/2)});
        sprite_->setPosition({p_position_x, p_position_y});
    }

    Paddle::~Paddle() {
        delete sprite_;
    }

    void Paddle::update(bool up_key_pressed, bool down_key_pressed) {
        if (up_key_pressed) {
            sprite_->move({0,-paddle_speed_});
        }
        else if (down_key_pressed) {
            sprite_->move({0,paddle_speed_});
        }
    }

    void Paddle::render(sf::RenderWindow *p_window) {
        p_window->draw(*sprite_);
    }
} // N_Gameplay