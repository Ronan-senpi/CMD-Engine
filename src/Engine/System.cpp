//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"
#include "../Utils/Input/Input.h"
#include "../Utils/Input/KeyCode.h"

void System::Run() {
	Start();
    int maxloop = 9999;

    while (isPlaying ) {
        if(Input::GetKeyDown(KeyCode::Escape)){
            std::cout << "Kill Game" << std::endl;
            isPlaying = false;
            break;
        }
        InternalUpdate();
        Time::Update();
    }
    //delete this;
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

//    while (FixedAcu >= fixedUpdateRate
//           && loop < MAX_LOOP) {
//        Scenes[selectedScene]->FixedUpdate();
//        FixedAcu -= fixedUpdateRate;
//        ++loop;
//    }
//    loop = 0;

	Update();
	LateUpdate();
}

void System::LateUpdate() {
    Scenes[selectedScene]->LateUpdate();
	//std::system("cls");
	std::cout << "Frame :" << frameCounter << std::endl;
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
    Time::FixedUpdate();
}
