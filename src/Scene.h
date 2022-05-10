//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SCENE_H
#define CMD_ENGINE_SCENE_H

#include <vector>

#include "Object.h"
#include "GameObject.h"

class Scene : public Object{

	int width = 0;
	int height = 0;
    std::vector<std::unique_ptr<GameObject>> gameObjects;
public:
    ~Scene();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;

	void SetSceneDimensions(int width, int height);

	void Instantiate(std::unique_ptr<GameObject> go);
};


#endif //CMD_ENGINE_SCENE_H
