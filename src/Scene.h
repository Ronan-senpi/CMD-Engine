//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SCENE_H
#define CMD_ENGINE_SCENE_H

#include <vector>

#include "Object.h"
#include "GameObject.h"

class Scene : public Object{

    std::vector<GameObject*> GameObjects;
public:
    ~Scene();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;
};


#endif //CMD_ENGINE_SCENE_H
