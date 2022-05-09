//
// Created by rdher on 09/05/2022.
//

#include "System.h"

void System::MainLoop() {

    Scenes[selectedScene]->Start();

    while (true) {
        Scenes[selectedScene]->Update();

        Scenes[selectedScene]->LateUpdate();
        ++frameCounter;

        //Clear Screen
        //Update Screen
    }
    Scenes[selectedScene]->FixedUpdate();
}

System::~System() {
    delete Scenes[selectedScene];
}
