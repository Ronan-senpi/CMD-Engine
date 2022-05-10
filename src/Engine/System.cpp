//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"

void System::Run() {
	Start();

    while (isPlaying) {
        InternalUpdate();
        Time::Update();
    }

}

System::~System() {
    delete Scenes[selectedScene];
}

void System::InternalUpdate() {

    timeAcu += Time::DeltaTime();
    while (timeAcu >= updateRate
           && loop < MAX_LOOP) {
		FixedUpdate();
        timeAcu -= updateRate;
        ++loop;
    }

    loop = 0;

	Update();
	LateUpdate();
}

void System::LateUpdate() {
    Scenes[selectedScene]->LateUpdate();
	std::system("cls");
	std::cout << "Frame :" << frameCounter;
	frameCounter++;
}

void System::Start() {
	Time::Start();
	Scenes[selectedScene]->Start();
}

void System::Update() {
	Scenes[selectedScene]->Update();
}

void System::FixedUpdate() {
	Scenes[selectedScene]->LateUpdate();
}
