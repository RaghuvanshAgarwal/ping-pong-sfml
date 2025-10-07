//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H
#include "GameplayManager.h"
#include "SFML/Graphics.hpp"


namespace N_Gameplay {
    class Paddle;
    class Ball {
        sf::Texture texture_;
        sf::Sprite* sprite_;

        std::string texture_path_ = std::string(PROJECT_ROOT) + "Assets/Textures/Ball.png";

        const float scale_x = 0.06f;
        const float scale_y = 0.06f;

        const float position_x_ = 610.0f;
        const float position_y_ = 335.0f;

        float speed_ = 250.0f;
        sf::Vector2f velocity_ = sf::Vector2f(speed_,speed_);
        bool is_left_collision_ = false;
        bool is_right_collision_ = false;

        void loadTexture();
        void initializeVariables();
        void move(N_Utility::TimeService* time_Service);
        void reset();
        void handlePaddleCollision(const Paddle* p_p1, const Paddle* p_p2);
        void handleBoundaryCollision();
        void handleOutOfBoundsCollision();
        void onCollision(const Paddle* p_p1, const Paddle* p_p2);


        public:
        Ball();
        ~Ball();
        void update(const Paddle* p_p1, const Paddle* p_p2, N_Utility::TimeService* time_Service);
        void render(sf::RenderWindow* p_window);
        bool isLeftCollisionOccured() const;
        bool isRightCollisionOccured() const;
        void updateLeftCollisionOccured(bool p_value);
        void updateRightCollisedOccured(bool p_value);

    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_BALL_H