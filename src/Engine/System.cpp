//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"
#include "../Components/ASCIIRenderer.h"
#include "../Utils/Input/Input.h"
#include "../Utils/Input/KeyCode.h"
#include <string>

void System::Run() {
	Start();
    std::cout << "Enter for start" << std::endl;

//    while (true){
//
//        if(Input::GetKeyDown(KeyCode::M)){
//            std::cout << "Start" << std::endl;
//            isPlaying = true;
//            break;
//        }
//    }

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
    Scene* s = Scenes[selectedScene];
	s->LateUpdate();

	//Clear
	std::system("cls");

	//RASTERISATION ASCII
	int width = s->getWidth();
	int height = s->getHeight();

	std::vector<std::string> map;
	for(int i = 0; i < height; i++){
		std::string line = "";
		for(int j = 0; j < width; j++){
			line += ".";
		}
		map.push_back(line);
	}

	for(GameObject* go : s->getGameObjects()){
		Transform* transform = go->getComponent<Transform>();
		ASCIIRenderer* renderer = go->getComponent<ASCIIRenderer>();
		int x = (int)transform->pos.x;
		int y = (int)transform->pos.y;
		x = std::max(x,0);
		y = std::max(y,0);
		x = std::min(x,s->getWidth()-1);
		y = std::min(y,s->getHeight()-1);
        map[y][x] = renderer->getAsciiValue();
	}

	//FINAL RENDER
	std::string render = "";
	for(int i = 0; i < map.size(); i++) {
		render += map[i] + "\n";
	}
	std::cout << render << std::endl;

	frameCounter++;
	if(frameCounter > 1000) isPlaying = false;
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
