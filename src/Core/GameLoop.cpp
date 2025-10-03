//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Core/GameLoop.h"

namespace N_Core {
    GameLoop::~GameLoop() {
        delete game_manager_;
        delete event_manager_;
        delete window_manager_;
    }

    void GameLoop::initialize() {
        window_manager_ = new GameWindowManager();
        event_manager_ = new N_Event::EventManager();
        game_manager_ = new N_Gameplay::GameplayManager(event_manager_);

        window_manager_->initialize();
    }

    bool GameLoop::isGameRunning() {
        if (window_manager_) {
            return window_manager_->isGameRunning();
        }
        return false;
    }

    void GameLoop::pollEvents() {
        if (window_manager_) {
            event_manager_->pollEvents(window_manager_->getGameWindow());
        }
    }

    void GameLoop::update() {
        game_manager_->update();
    }

    void GameLoop::render() {
        window_manager_->clearGameWindow();
        game_manager_->render(window_manager_->getGameWindow());
        window_manager_->renderGameWindow();
    }
}
