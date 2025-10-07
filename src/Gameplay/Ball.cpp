//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/Ball.h"

#include "../../include/Gameplay/Paddle.h"
#include "../../include/Sound/SoundManager.h"
#include "../../include/Utility/TimeService.h"

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

    void Ball::move(N_Utility::TimeService* time_Service) {
        sprite_->move(velocity_ * time_Service->getDeltaTime());
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

    void Ball::update(const Paddle* p_p1, const Paddle* p_p2, N_Utility::TimeService* time_Service) {
        move(time_Service);
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

    bool Ball::isLeftCollisionOccured() const {
        return is_left_collision_;
    }

    bool Ball::isRightCollisionOccured() const {
        return is_right_collision_;
    }

    void Ball::updateLeftCollisionOccured(bool p_value) {
        is_left_collision_ = p_value;
    }

    void Ball::updateRightCollisedOccured(bool p_value) {
        is_right_collision_ = p_value;
    }

    void Ball::handlePaddleCollision(const Paddle *p_p1, const Paddle *p_p2) {
        const sf::FloatRect player_1_bounds = p_p1->getSprite()->getGlobalBounds();
        const sf::FloatRect player_2_bounds = p_p2->getSprite()->getGlobalBounds();
        const sf::FloatRect own_bounds = sprite_->getGlobalBounds();

        if (own_bounds.findIntersection(player_1_bounds) && velocity_.x < 0) {
            velocity_.x = -velocity_.x;
            N_Sound::SoundManager::getInstance().playSoundEffect(N_Sound::SOUND_TYPE::Bounce);
        }

        if (own_bounds.findIntersection(player_2_bounds)&& velocity_.x > 0) {
            velocity_.x = -velocity_.x;
            N_Sound::SoundManager::getInstance().playSoundEffect(N_Sound::SOUND_TYPE::Bounce);
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
            updateLeftCollisionOccured(true);
        }
        else if ((bounds.size.x + bounds.position.x) > 1280) {
            reset();
            updateRightCollisedOccured(true);
        }
    }
} // N_Gameplay