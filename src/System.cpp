//
// Created by rdher on 09/05/2022.
//

#include "System.h"

void System::MainLoop() {
    this->Start();

}

void System::Start() {
    Scenes[selectedScene]->Start();
}

void System::Update() {
    Scenes[selectedScene]->Update();
}

void System::FixedUpdate() {
    Scenes[selectedScene]->FixedUpdate();
}

void System::LateUpdate() {
    Scenes[selectedScene]->LateUpdate();
    //Clear Screen
    //Update Screen
}

System::~System() {
    delete Scenes[selectedScene];
}
