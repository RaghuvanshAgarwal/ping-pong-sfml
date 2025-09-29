#include <iostream>

#include "include/Core/GameWindowManager.h"
int main()
{
    Core::GameWindowManager game_window_manager;

    game_window_manager.initialize();
    while (game_window_manager.is_game_running()) {
        N_Event::EventManager::pollEvents(game_window_manager.get_game_window());
        game_window_manager.render();
    }



    return 0;
}
