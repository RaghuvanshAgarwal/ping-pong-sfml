//
// Created by Raghuvansh Agarwal on 06/10/25.
//

#include "../../include/UI/UIService.h"

namespace N_UI {
    void UIService::loadFromFile() {
        if (!font_.openFromFile(font_path_)) {
            throw std::runtime_error("Could not open font file: " + std::string(font_path_));
        }
    }

    void UIService::createLeftScoreText() {
        left_score_text_ = new sf::Text(font_,initial_string_,font_size_);
        left_score_text_->setFillColor(font_color_);
        left_score_text_->setPosition({left_score_position_x_, left_score_position_y_});
    }

    void UIService::createRightScoreText() {
        right_score_text_= new sf::Text(font_,initial_string_,font_size_);
        right_score_text_->setFillColor(font_color_);
        right_score_text_->setPosition({right_score_position_x_, right_score_position_y_});
    }

    UIService::UIService() {
        loadFromFile();
        createLeftScoreText();
        createRightScoreText();
    }

    UIService::~UIService() {
        delete left_score_text_;
        delete right_score_text_;
    }

    void UIService::render(sf::RenderWindow *window) {
        window->draw(*left_score_text_);
        window->draw(*right_score_text_);
    }
} // N_UI