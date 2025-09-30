//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_GAMEPLAYMANAGER_H
#define CMAKESFMLPROJECT_GAMEPLAYMANAGER_H
#include "SFML/Graphics.hpp"

namespace N_Gameplay {
    class Paddle;
}

namespace N_Gameplay {
    class Ball;
}

namespace N_Gameplay {
    class GameplayManager {
        float player_1_position_x_ = 40.0f;
        float player_1_position_y_ = 300.f;

        float player_2_position_x_ = 1210.0f;
        float player_2_position_y_ = 300.0f;

        Ball* ball_;
        Paddle* player_1_;
        Paddle* player_2_;

        void initialize();
    public:
        GameplayManager();
        ~GameplayManager();
        void update();
        void render(sf::RenderWindow* p_window);
    };
} // N_Gameplay

#endif //CMAKESFMLPROJECT_GAMEPLAYMANAGER_H