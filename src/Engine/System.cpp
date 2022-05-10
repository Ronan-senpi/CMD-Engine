//
// Created by rdher on 09/05/2022.
//

#include "System.h"
#include "Time.h"
#include "../Components/ASCIIRenderer.h"

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

	for(std::unique_ptr<GameObject>& go : s->getGameObjects()){
		std::unique_ptr<Transform>& transform = go->getComponent<Transform>();
		std::unique_ptr<ASCIIRenderer>& renderer = go->getComponent<ASCIIRenderer>();

		Position p = transform->GetPosition();
		map[p.y][p.x] = renderer->getAsciiValue();
	}

	//FINAL RENDER
	std::string render = "";
	for(int i = 0; i < map.size(); i++) {
		render += map[i] + "\n";
	}
	std::cout << render << std::endl;

	frameCounter++;
	if(frameCounter > 500) isPlaying = false;
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
