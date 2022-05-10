//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"

void System::Run() {
    Time::Start();
    Scenes[selectedScene]->Start();

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
    //
    while (timeAcu >= updateRate
           && loop < MAX_LOOP) {
        Scenes[selectedScene]->Update();
        Scenes[selectedScene]->LateUpdate();
        timeAcu -= updateRate;
        ++loop;
    }
    loop = 0;

    while (FixedAcu >= fixedUpdateRate
           && loop < MAX_LOOP) {
        Scenes[selectedScene]->Update();
        Scenes[selectedScene]->LateUpdate();
        FixedAcu -= fixedUpdateRate;
        ++loop;
    }
    loop = 0;

//Clear Screen
//Update Screen
}

