//
// Created by Raghuvansh Agarwal on 29/09/25.
//

#ifndef CMAKESFMLPROJECT_EVENTMANAGER_H
#define CMAKESFMLPROJECT_EVENTMANAGER_H


namespace sf {
    namespace Keyboard {
        enum class Key;
    }

    class RenderWindow;
}

namespace N_Event {
    class EventManager {
    public:
        static void pollEvents(sf::RenderWindow* p_window);
        static bool isKeyPressed(sf::Keyboard::Key p_key);
        static bool isLeftMouseButtonPressed();
    };
}

#endif //CMAKESFMLPROJECT_EVENTMANAGER_H