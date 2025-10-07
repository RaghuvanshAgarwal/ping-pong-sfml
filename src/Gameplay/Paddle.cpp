//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Paddle.h"

#include <iostream>

#include "../../include/Utility/TimeService.h"

namespace N_Gameplay {
    void Paddle::loadFromFile() {
        if (!texture_.loadFromFile(std::string(PROJECT_ROOT) +"Assets/Textures/Paddle.png")) {
            throw std::runtime_error("Failed to load paddle texture");
        }
    }

    void Paddle::initializeSprite(float p_position_x, float p_position_y) {
        sprite_ = new sf::Sprite(texture_);
        sprite_->setScale({paddle_height_ / texture_.getSize().x, paddle_width_ / texture_.getSize().y});
        sprite_->setRotation(sf::Literals::operator ""_deg(90.0l));
        sprite_->setOrigin({static_cast<float>(texture_.getSize().x/2),static_cast<float>(texture_.getSize().y/2)});
        sprite_->setPosition({p_position_x, p_position_y});
    }

    void Paddle::movePaddle(bool up_key_pressed, bool down_key_pressed, N_Utility::TimeService* time_Service) {
        const float top = sprite_->getGlobalBounds().position.y;
        const float down = sprite_->getGlobalBounds().position.y + sprite_->getGlobalBounds().size.y;
        if (up_key_pressed && top > 20) {
            sprite_->move({0,-paddle_speed_ * time_Service->getDeltaTime()});
        }
        else if (down_key_pressed && down < 700) {
            sprite_->move({0,paddle_speed_  * time_Service->getDeltaTime()});
        }
        sprite_->setPosition({position_x_, std::clamp(sprite_->getPosition().y,20.f,700.f)});
    }

    Paddle::Paddle(float p_position_x, float p_position_y) {
        loadFromFile();
        initializeSprite(p_position_x, p_position_y);
        position_x_ = p_position_x;
        position_y_ = p_position_y;
    }

    Paddle::~Paddle() {
        delete sprite_;
    }

    void Paddle::update(bool up_key_pressed, bool down_key_pressed, N_Utility::TimeService* time_Service) {
        movePaddle(up_key_pressed, down_key_pressed, time_Service);
    }

    void Paddle::render(sf::RenderWindow *p_window) {
        p_window->draw(*sprite_);
    }

    const sf::Sprite * Paddle::getSprite() const {
        return sprite_;
    }

    void Paddle::reset() {
        sprite_->setPosition({position_x_, position_y_});
    }
} // N_Gameplay