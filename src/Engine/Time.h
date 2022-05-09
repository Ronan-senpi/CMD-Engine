//
// Created by rdher on 09/05/2022.
//

#pragma once


#include <chrono>
#include <vector>
#include <functional>

namespace Time {
   static std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;
   static std::chrono::duration<float> elapsedTime;

    static void Start(){
        startTime = endTime = std::chrono::high_resolution_clock ::now();
    }

    static void Update(){
        startTime = std::chrono::high_resolution_clock ::now();
        elapsedTime = startTime - endTime;
        endTime = startTime;
    }

    static float DeltaTime(){
        return elapsedTime.count();
    }
}