//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics.hpp"

namespace N_Gameplay {
    class Paddle {
        sf::Sprite* sprite_;
        sf::Texture texture_;

        const float paddle_width_ = 20.0f;
        const float paddle_height_ = 140.0f;
        const float paddle_speed_ = 5.0f;

        void movePaddle(bool up_key_pressed, bool down_key_pressed);
    public:
        Paddle(float p_position_x,float p_position_y);
        ~Paddle();
        void update(bool up_key_pressed, bool down_key_pressed);
        void render(sf::RenderWindow *p_window);
        const sf::Sprite* getSprite() const;
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_PADDLE_H