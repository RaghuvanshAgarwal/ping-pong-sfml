//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H
#include "SFML/Graphics.hpp"


namespace N_Gameplay {
    class Ball {
        sf::CircleShape ball_sprite_;
        const float radius_ = 10.0f;
        const float position_x_ = 615.0f;
        const float position_y_ = 335.0f;
        public:
        Ball();
        ~Ball();
        void update();
        void render(sf::RenderWindow* p_window);
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_BALL_H