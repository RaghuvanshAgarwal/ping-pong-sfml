//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "GameplayManager.h"
#include "SFML/Graphics.hpp"

namespace N_Gameplay {
    class Paddle {
        sf::Sprite* sprite_;
        sf::Texture texture_;

        const float paddle_width_ = 20.0f;
        const float paddle_height_ = 140.0f;
        const float paddle_speed_ = 360.0f;
        float position_x_;
        float position_y_;

        void movePaddle(bool up_key_pressed, bool down_key_pressed);
    public:
        Paddle(float p_position_x,float p_position_y);
        ~Paddle();
        void update(bool up_key_pressed, bool down_key_pressed, N_Utility::TimeService* time_Service);
        void render(sf::RenderWindow *p_window);
        const sf::Sprite* getSprite() const;

        void reset();
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_PADDLE_H