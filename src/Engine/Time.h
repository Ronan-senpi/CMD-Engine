//
// Created by rdher on 09/05/2022.
//

#pragma once

#include <chrono>
#include <vector>
#include <functional>

namespace Time {
   static std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime,fixedStartTime, fixedEndTime;
   static std::chrono::duration<float> elapsedTime, fixedElapsedTime;

    static void Start(){
        startTime = endTime = fixedStartTime = fixedEndTime = std::chrono::high_resolution_clock::now();
    }

    /**
     * Calculate DeltaTime
     */
    static void Update(){
        startTime = std::chrono::high_resolution_clock ::now();
        elapsedTime = startTime - endTime;
        endTime = startTime;
    }

    /**
     * The interval in seconds from the last frame to the current one (Read Only).
     * @return
     */
    static float DeltaTime(){
        return elapsedTime.count();
    }

    static void FixedUpdate(){
        fixedStartTime = std::chrono::high_resolution_clock::now();
        fixedElapsedTime = fixedStartTime - fixedEndTime;
        fixedEndTime = fixedStartTime;
    }

    /**
     * TThe interval in seconds at which "physics" and other fixed frame rate updates (ReadOnly)
     * @return
     */
    static float FixedDeltaTime(){
        return fixedElapsedTime.count();
    }
}