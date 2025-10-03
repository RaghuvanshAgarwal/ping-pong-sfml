//
// Created by Raghuvansh Agarwal on 30/09/25.
//

#ifndef CMAKESFMLPROJECT_BOUNDARY_H
#define CMAKESFMLPROJECT_BOUNDARY_H
#include <SFML/Graphics.hpp>

class Boundary {
    sf::RectangleShape top_boundary_;
    sf::RectangleShape bottom_boundary_;
    sf::RectangleShape left_boundary_;
    sf::RectangleShape right_boundary_;
    sf::RectangleShape center_line_;

    float center_line_width_ = 5;
    float boundary_width_ = 20;

    sf::Color boundary_color_ = sf::Color::Blue;
    sf::Color center_line_color_ = sf::Color::White;

    static void initializeShape(sf::RectangleShape& p_shape, sf::Vector2f p_position, sf::Vector2f p_size, sf::Color p_color);

    public:
    Boundary();
    void render(sf::RenderWindow* p_window);
};


#endif //CMAKESFMLPROJECT_BOUNDARY_H