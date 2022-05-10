//
// Created by rdher on 09/05/2022.
//

#include "System.h"

void System::MainLoop() {
    this->Start();

}

void System::Start() {
    Scenes[selectedScene]->Start();
	int count = 20;
	while(count >= 0){
		LateUpdate();
		count--;
	}
}

void System::Update() {
    Scenes[selectedScene]->Update();
}

void System::FixedUpdate() {
    Scenes[selectedScene]->FixedUpdate();
}

void System::LateUpdate() {
    Scenes[selectedScene]->LateUpdate();
	std::cout << std::flush;
	std::cout << "Frame :" << frameCounter;
	frameCounter++;
}

System::~System() {
    delete Scenes[selectedScene];
}
