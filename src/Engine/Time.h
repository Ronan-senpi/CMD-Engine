//
// Created by rdher on 09/05/2022.
//

#pragma once


#include <chrono>
#include <vector>
#include <functional>

namespace Time {
    std::chrono::steady_clock::time_point StartTime = std::chrono::steady_clock::now();

    float DeltaTime;
}