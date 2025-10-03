//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Ball.h"

#include "../../include/Gameplay/Paddle.h"

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

    void Ball::move() {
        sprite_->move(velocity_);
    }

    void Ball::reset() {
        sprite_->setPosition({position_x_,position_y_});
        velocity_ = {speed_,speed_};
    }

    Ball::Ball() {
        loadTexture();
        initializeVariables();
    }

    Ball::~Ball() {
        delete sprite_;
    }

    void Ball::update(const Paddle* p_p1, const Paddle* p_p2) {
        move();
        onCollision(p_p1, p_p2);
    }

    void Ball::onCollision(const Paddle* p_p1, const Paddle* p_p2) {
        handlePaddleCollision(p_p1,p_p2);
        handleBoundaryCollision();
        handleOutOfBoundsCollision();
    }

    void Ball::render(sf::RenderWindow *p_window) {
        p_window->draw(*sprite_);
    }

    void Ball::handlePaddleCollision(const Paddle *p_p1, const Paddle *p_p2) {
        const sf::FloatRect player_1_bounds = p_p1->getSprite()->getGlobalBounds();
        const sf::FloatRect player_2_bounds = p_p2->getSprite()->getGlobalBounds();
        const sf::FloatRect own_bounds = sprite_->getGlobalBounds();

        if (own_bounds.findIntersection(player_1_bounds) && velocity_.x < 0) {
            velocity_.x = -velocity_.x;
        }

        if (own_bounds.findIntersection(player_2_bounds)&& velocity_.x > 0) {
            velocity_.x = -velocity_.x;
        }
    }

    void Ball::handleBoundaryCollision() {
        const sf::FloatRect bounds = sprite_->getGlobalBounds();
        if ((bounds.position.y < 20 && velocity_.y < 0) || (bounds.position.y + bounds.size.y > 700 && velocity_.y > 0)) {
            velocity_.y = -velocity_.y;
        }
    }

    void Ball::handleOutOfBoundsCollision() {
        const sf::FloatRect bounds = sprite_->getGlobalBounds();
        if (bounds.position.x < 0) {
            reset();
        }
        else if ((bounds.size.x + bounds.position.x) > 1280) {
            reset();
        }
    }
} // N_Gameplay