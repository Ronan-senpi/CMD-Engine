//
// Created by rdher on 09/05/2022.
//

#include "System.h"

void System::Run() {
    Scenes[selectedScene]->Start();

    while (keepRunning = true) {
        InternalUpdate();
    }

}

System::~System() {
    delete Scenes[selectedScene];
}

void System::InternalUpdate() {


        Scenes[selectedScene]->Update();
        Scenes[selectedScene]->LateUpdate();

        if(frameCounter % 2 == 0) {
            Scenes[selectedScene]->FixedUpdate();
        }
        ++frameCounter;

        //Clear Screen
        //Update Screen
    }

}
