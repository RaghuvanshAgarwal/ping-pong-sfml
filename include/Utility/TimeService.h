//
// Created by Raghuvansh Agarwal on 06/10/25.
//

#ifndef CMAKESFMLPROJECT_TIMESERVICE_H
#define CMAKESFMLPROJECT_TIMESERVICE_H
#include <chrono>

namespace N_Utility {
    class TimeService {
        std::chrono::steady_clock::time_point previousTime;
        float deltaTime;

        void updateDeltaTime();
        float calculateDeltaTime() const;
        void updatePreviousTime();

        public:
        void initialize();
        void update();
        float getDeltaTime() const;

    };
} // N_Utility

#endif //CMAKESFMLPROJECT_TIMESERVICE_H