//
// Created by Raghuvansh Agarwal on 30/09/25.
//

#include "../../include/Gameplay/Boundary.h"

void Boundary::initializeShape(sf::RectangleShape &p_shape, sf::Vector2f p_position, sf::Vector2f p_size, sf::Color p_color) {
    p_shape.setPosition(p_position);
    p_shape.setSize(p_size);
    p_shape.setFillColor(p_color);
}

Boundary::Boundary() {
    constexpr float screen_width = 1280;
    constexpr float screen_height = 720;
    initializeShape(top_boundary_, {0,0},{screen_width,boundary_width_},boundary_color_);
    initializeShape(bottom_boundary_, {0,screen_height - boundary_width_}, {screen_width,boundary_width_}, boundary_color_);
    initializeShape(left_boundary_, {0,boundary_width_}, {boundary_width_,screen_height - boundary_width_* 2}, boundary_color_);
    initializeShape(right_boundary_,{screen_width - boundary_width_,boundary_width_},{boundary_width_,screen_height - boundary_width_* 2}, boundary_color_);

    initializeShape(center_line_, {static_cast<float>((screen_width - center_line_width_) * 0.5), boundary_width_}, {center_line_width_,screen_height - boundary_width_* 2}, center_line_color_);
}

void Boundary::render(sf::RenderWindow *p_window) {
    p_window->draw(top_boundary_);
    p_window->draw(bottom_boundary_);
    p_window->draw(left_boundary_);
    p_window->draw(right_boundary_);
    p_window->draw(center_line_);
}
