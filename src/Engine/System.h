//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SYSTEM_H
#define CMD_ENGINE_SYSTEM_H

#include <utility>
#include <vector>
#include "../Abstract/Object.h"
#include "Scene.h"

struct System {
private:
    bool keepRunning = true;
    std::vector<Scene*> Scenes;
    int selectedScene = 0;
    int frameCounter = 0;

public:
    inline System(const std::vector<Scene*>& s): Scenes(s){}

    void Run();
    void InternalUpdate();


    ~System();
};


#endif //CMD_ENGINE_SYSTEM_H
