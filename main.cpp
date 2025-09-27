#include <iostream>

#include "include/core/GameWindowManager.h"
int main()
{
    Core::GameWindowManager game_window_manager;

    game_window_manager.initialize();
    while (game_window_manager.is_game_running()) {
        game_window_manager.take_input();
        game_window_manager.render();
    }



    return 0;
}
