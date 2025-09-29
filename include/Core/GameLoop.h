//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_GAMELOOP_H
#define CMAKESFMLPROJECT_GAMELOOP_H
#include "GameWindowManager.h"

namespace N_Core {
    class GameLoop {
        GameWindowManager* window_manager_;
        N_Event::EventManager* event_manager_;
    public:
        void initialize();
        bool isGameRunning();
        void pollEvents();
        void update();
        void render();
    };
}

#endif //CMAKESFMLPROJECT_GAMELOOP_H