//
// Created by rdher on 09/05/2022.
//

#include "System.h"

void System::Start() {
    for (int i = 0; i < Scenes[selectedScene].Objects.size(); ++i) {
        Scenes[selectedScene].Objects[i].Start();
    }
}

void System::Update() {
    for (int i = 0; i < Scenes[selectedScene].Objects.size(); ++i) {
        Scenes[selectedScene].Objects[i].Update();
    }
}

void System::FixedUpdate() {
    for (int i = 0; i < Scenes[selectedScene].Objects.size(); ++i) {
        Scenes[selectedScene].Objects[i].FixedUpdate();
    }
}

void System::LateUpdate() {
    for (int i = 0; i < Scenes[selectedScene].Objects.size(); ++i) {
        Scenes[selectedScene].Objects[i].LateUpdate();
    }
    //Clear Screen
    //Update Screen
}

System::~System() {
    for (int i = 0; i < Scenes[selectedScene].Objects.size(); ++i) {
        Scenes[selectedScene].Objects[i].Destroy();
    }
}
