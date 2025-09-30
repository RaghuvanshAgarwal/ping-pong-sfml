//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H
#include "SFML/Graphics.hpp"


namespace N_Gameplay {
    class Ball {
        sf::Texture texture_;
        sf::Sprite* sprite_;

        std::string texture_path_ = std::string(PROJECT_ROOT) + "/Assets/Textures/Ball.png";

        const float scale_x = 0.06f;
        const float scale_y = 0.06f;

        const float position_x_ = 615.0f;
        const float position_y_ = 335.0f;

        void loadTexture();
        void initializeVariables();

        public:
        Ball();
        ~Ball();
        void update();
        void render(sf::RenderWindow* p_window);
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_BALL_H