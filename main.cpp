#include <iostream>

#include "include/Core/GameLoop.h"
#include "include/Core/GameWindowManager.h"
int main()
{
    auto* loop = new N_Core::GameLoop();
    loop->initialize();
    while (loop->isGameRunning()) {
        loop->pollEvents();
        loop->update();
        loop->render();
    }
    delete loop;
    return 0;
}
