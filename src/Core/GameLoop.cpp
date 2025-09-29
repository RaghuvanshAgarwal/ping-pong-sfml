//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#include "../../include/Core/GameLoop.h"

namespace N_Core {
    void GameLoop::initialize() {
        window_manager_ = new GameWindowManager();
        event_manager_ = new N_Event::EventManager();

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
    }

    void GameLoop::render() {
        window_manager_->clearGameWindow();
        window_manager_->renderGameWindow();
    }
}
