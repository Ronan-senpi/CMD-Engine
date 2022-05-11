//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SYSTEM_H
#define CMD_ENGINE_SYSTEM_H

#include <utility>
#include <vector>
#include "../Abstract/Object.h"
#include "Scene.h"

struct System {
private:
    bool clear_frame = true;
//    bool needStart = false;
    bool isPlaying = true;
    std::vector<Scene*> Scenes;
    int selectedScene = 0;
    int frameCounter = 0;
    static const int MAX_LOOP = 5;
    int loop = 0;
    float timeAcu = 0;
    float FixedAcu = 0;
    static constexpr float updateRate = 1.f / 144.f;
    static constexpr float fixedUpdateRate = 1.f / 30.f;

public:
    inline System(const std::vector<Scene*>& s): Scenes(s){}

    void Run();
    void InternalUpdate();

	void Start();

	void Update();

	void FixedUpdate();

	void LateUpdate();


    ~System();
};


#endif //CMD_ENGINE_SYSTEM_H
