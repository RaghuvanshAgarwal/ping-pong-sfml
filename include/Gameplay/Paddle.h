//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_PADDLE_H
#define CMAKESFMLPROJECT_PADDLE_H
#include "SFML/Graphics.hpp"

namespace N_Gameplay {
    class Paddle {
        sf::RectangleShape paddle_sprite_;

        const float paddle_width_ = 20.0f;
        const float paddle_height_ = 140.0f;
    public:
        Paddle(float p_position_x,float p_position_y);
        ~Paddle();
        void update();
        void render(sf::RenderWindow *p_window);
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_PADDLE_H