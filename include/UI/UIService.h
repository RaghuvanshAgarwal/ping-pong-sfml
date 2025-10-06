//
// Created by Raghuvansh Agarwal on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_UISERVICE_H
#define CMAKESFMLPROJECT_UISERVICE_H
#include "SFML/Graphics.hpp"


namespace N_UI {
    class UIService {
        sf::Font font_;
        sf::Text* left_score_text_{};
        sf::Text* right_score_text_{};

        std::string font_path_ = std::string(PROJECT_ROOT) + "/Assets/Fonts/Aloevera-OVoWO.ttf";
        int font_size_ = 40;
        sf::Color font_color_ = sf::Color::White;
        std::string initial_string_ = "00";

        float left_score_position_x_ = 570.0f;
        float left_score_position_y_ = 30.0f;

        float right_score_position_x_ = 670.0f;
        float right_score_position_y_ = 30.0f;

        int player_1_score_ = 0;
        int player_2_score_ = 0;

        void loadFromFile();
        void createLeftScoreText();
        void createRightScoreText();

        public:
        UIService();
        ~UIService();
        void render(sf::RenderWindow* window);
    };
} // N_UI

#endif //CMAKESFMLPROJECT_UISERVICE_H