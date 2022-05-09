//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"
void System::Run() {
    Time::Start();
    Scenes[selectedScene]->Start();

    while (keepRunning = true) {
        Time::Update();
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
    
