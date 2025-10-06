//
// Created by Raghuvansh Agarwal on 06/10/25.
//

#include "../../include/Utility/TimeService.h"

namespace N_Utility {
    void TimeService::updateDeltaTime() {
        deltaTime = calculateDeltaTime();
    }

    float TimeService::calculateDeltaTime() const {
        const long long count = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousTime).count();
        return static_cast<float>(count) / 1000000.0f; // microseconds to seconds
    }

    void TimeService::updatePreviousTime() {
        previousTime = std::chrono::steady_clock::now();
    }

    void TimeService::initialize() {
        previousTime = std::chrono::steady_clock::now();
        deltaTime = 0;
    }

    void TimeService::update() {
        updateDeltaTime();
        updatePreviousTime();
    }

    float TimeService::getDeltaTime() const {
        return deltaTime;
    }
} // N_Utility