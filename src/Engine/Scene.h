//
// Created by rdher on 09/05/2022.
//

#ifndef CMD_ENGINE_SCENE_H
#define CMD_ENGINE_SCENE_H

#include <vector>

#include "../Abstract/Object.h"
#include "../Objects/GameObject.h"

class Scene : public Object {

    int width = 0;
    int height = 0;
    std::vector<GameObject *> gameObjects;
public:
    ~Scene();

    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;

    void SetSceneDimensions(int width, int height);

    int getWidth() const;

    int getHeight() const;

    void Instantiate(GameObject *go);

    std::vector<GameObject *> findObjectWithTags(int tag);

    std::vector<GameObject *> &getGameObjects();
};


#endif //CMD_ENGINE_SCENE_H
