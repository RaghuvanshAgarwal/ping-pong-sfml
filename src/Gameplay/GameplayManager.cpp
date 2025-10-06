//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Gameplay/GameplayManager.h"
#include "../../include/Gameplay/Ball.h"
#include "../../include/Gameplay/Paddle.h"
#include "../../include/Gameplay/Boundary.h"
#include "../../include/Event/EventManager.h"
#include "../../include/Utility/TimeService.h"
#include "../../include/UI/UIService.h"

namespace N_Gameplay {
    void GameplayManager::initialize() {
        boundary_ = new Boundary();
        player_1_ = new Paddle(player_1_position_x_, player_1_position_y_);
        player_2_ = new Paddle(player_2_position_x_, player_2_position_y_);
        ball_ = new Ball();
    }

    GameplayManager::GameplayManager(N_Event::EventManager* p_event_manager) {
        eventManager_ = p_event_manager;
        timeService_ = new N_Utility::TimeService();
        uiService_ = new N_UI::UIService();
        timeService_->initialize();
        initialize();
    }

    GameplayManager::~GameplayManager() {
        delete boundary_;
        delete player_1_;
        delete player_2_;
        delete ball_;
    }

    void GameplayManager::update() {
        timeService_->update();
        player_1_->update(
            eventManager_->isKeyPressed(sf::Keyboard::Key::W),
            eventManager_->isKeyPressed(sf::Keyboard::Key::S),
            timeService_);
        player_2_->update(
            eventManager_->isKeyPressed(sf::Keyboard::Key::Up),
            eventManager_->isKeyPressed(sf::Keyboard::Key::Down),
            timeService_
            );
        ball_->update(player_1_, player_2_,timeService_);
    }

    void GameplayManager::render(sf::RenderWindow *p_window) {
        boundary_->render(p_window);
        player_1_->render(p_window);
        player_2_->render(p_window);
        ball_->render(p_window);
        uiService_->render(p_window);
    }
} // N_Gameplay