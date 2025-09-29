#include <iostream>

#include "include/Core/GameLoop.h"
#include "include/Core/GameWindowManager.h"
int main()
{
    N_Core::GameLoop* loop = new N_Core::GameLoop();
    loop->initialize();
    while (loop->isGameRunning()) {
        loop->pollEvents();
        loop->update();
        loop->render();
    }
    delete loop;
    return 0;
}
